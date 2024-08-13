#pragma once

#include<QtWidgets/QWidget>
#include<thread>
#include<atomic>
#include "ui_TestRGB.h"

class TestRGB : public QWidget
{
    Q_OBJECT

public:
    TestRGB(QWidget* parent = nullptr);
    //用于刷新视频
    void thraed_func();
    ~TestRGB();
signals:
    void ViewS();
public slots:
    void View();
    void Open1();
    void Open2();
    void Open(int i);
private:
    std::thread t_;
    std::atomic_bool is_exit_;
    Ui::TestRGBClass ui;
};