#include "TestRGB.h"
#include<QMessagebox>
#include<QString>
#include<QSpinBox>
#include<QFileDialog>
#include<fstream>
#include<iostream>
#include<chrono>
#include<sstream>
#include<vector>
#include<sstream>
#include"xvideoview.h"

static std::vector<XVideoView*> views;

TestRGB::TestRGB(QWidget *parent)
    : QWidget(parent),is_exit_(false){
    ui.setupUi(this);
    //渲染
    QObject::connect(this, &TestRGB::ViewS, this, &TestRGB::View);

    views.push_back(XVideoView::Create());
    views.push_back(XVideoView::Create());
    views[0]->set_win_id((void*)ui.video1->winId());
    views[1]->set_win_id((void*)ui.video2->winId());

    t_ = std::thread(&TestRGB::thraed_func,this);

}

void TestRGB::View() {
    //存放上次渲染的时间戳
    static int last_pts[32]{ 0 };
    static int fps_arr[32]{ 0 };
    fps_arr[0] = ui.set_fps1->value();
    fps_arr[1] = ui.set_fps2->value();
    for (int i = 0; i < views.size(); i++) {
        if (fps_arr[i] <= 0) { continue; }
        //需要间隔时间
        int ms = 1000 / fps_arr[i];

        //判断是否到了可渲染时间
        if (NowMs() - last_pts[i] < ms) { continue; }
        last_pts[i] = NowMs();

        auto frame = views[i]->Read();          //读取一帧
        if (!frame) { continue; }
        views[i]->DrawFrame(frame);
        //显示FPS
        std::stringstream ss;
        ss << "FPS:" << views[i]->render_fps();
        if (i == 0) {
            ui.fps1->setText(ss.str().c_str());
        }
        else {
            ui.fps2->setText(ss.str().c_str());
        }
   }
}

void TestRGB::thraed_func(){
    while (!is_exit_) {
        emit ViewS();
        MSleep(1);
    }
}

void TestRGB::Open1() {
    Open(0);
}

void TestRGB::Open2() {
    Open(1);
}

void TestRGB::Open(int i) {
    QFileDialog fd;
    auto filename = fd.getOpenFileName();
    if (filename.isEmpty()) { return; }
    std::cout << filename.toLocal8Bit().data() << std::endl;
    if (!views[i]->Open(filename.toLocal8Bit().toStdString())) {return;}
    int w = 0;
    int h = 0;
    QString pix;
    if (i == 0) {
        w = ui.width1->value();
        h = ui.height1->value();
        pix = ui.pix1->currentText();               //像素格式
    }
    else {
        w = ui.width2->value();
        h = ui.height2->value();
        pix = ui.pix2->currentText();
    }
    XVideoView::Format fmt = XVideoView::YUV420P;
    if (pix == "YUV420P") {
        
    }
    else if (pix == "RGBA") {
        fmt = XVideoView::RGBA;
    }
    else if (pix == "ARGB") {
        fmt = XVideoView::ARGB;
    }
    else if (pix == "BGRA") {
        fmt = XVideoView::BGRA;
    }
    //Init窗口
    views[i]->Init(w,h,fmt);
}

TestRGB::~TestRGB(){
    is_exit_ = true;
    t_.join();
}
