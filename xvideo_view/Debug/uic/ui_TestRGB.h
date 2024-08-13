/********************************************************************************
** Form generated from reading UI file 'TestRGB.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTRGB_H
#define UI_TESTRGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestRGBClass
{
public:
    QLabel *video1;
    QLabel *video2;
    QPushButton *open1;
    QComboBox *pix1;
    QSpinBox *width1;
    QSpinBox *height1;
    QSpinBox *set_fps1;
    QSpinBox *height2;
    QComboBox *pix2;
    QPushButton *open2;
    QSpinBox *width2;
    QSpinBox *set_fps2;
    QLabel *fps1;
    QLabel *fps2;

    void setupUi(QWidget *TestRGBClass)
    {
        if (TestRGBClass->objectName().isEmpty())
            TestRGBClass->setObjectName(QString::fromUtf8("TestRGBClass"));
        TestRGBClass->resize(800, 800);
        TestRGBClass->setMinimumSize(QSize(800, 800));
        TestRGBClass->setMaximumSize(QSize(800, 16777215));
        video1 = new QLabel(TestRGBClass);
        video1->setObjectName(QString::fromUtf8("video1"));
        video1->setGeometry(QRect(10, 149, 351, 321));
        video1->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 226, 255);"));
        video2 = new QLabel(TestRGBClass);
        video2->setObjectName(QString::fromUtf8("video2"));
        video2->setGeometry(QRect(370, 150, 351, 321));
        video2->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 255, 243);"));
        open1 = new QPushButton(TestRGBClass);
        open1->setObjectName(QString::fromUtf8("open1"));
        open1->setGeometry(QRect(190, 480, 80, 20));
        pix1 = new QComboBox(TestRGBClass);
        pix1->addItem(QString());
        pix1->addItem(QString());
        pix1->addItem(QString());
        pix1->addItem(QString());
        pix1->setObjectName(QString::fromUtf8("pix1"));
        pix1->setGeometry(QRect(40, 480, 121, 21));
        width1 = new QSpinBox(TestRGBClass);
        width1->setObjectName(QString::fromUtf8("width1"));
        width1->setGeometry(QRect(40, 510, 121, 21));
        width1->setMinimum(1);
        width1->setMaximum(99999);
        width1->setValue(400);
        height1 = new QSpinBox(TestRGBClass);
        height1->setObjectName(QString::fromUtf8("height1"));
        height1->setGeometry(QRect(40, 540, 121, 21));
        height1->setMinimum(1);
        height1->setMaximum(99999);
        height1->setValue(300);
        set_fps1 = new QSpinBox(TestRGBClass);
        set_fps1->setObjectName(QString::fromUtf8("set_fps1"));
        set_fps1->setGeometry(QRect(40, 570, 121, 21));
        set_fps1->setMinimum(1);
        set_fps1->setMaximum(300);
        set_fps1->setValue(25);
        height2 = new QSpinBox(TestRGBClass);
        height2->setObjectName(QString::fromUtf8("height2"));
        height2->setGeometry(QRect(370, 540, 121, 21));
        height2->setMinimum(1);
        height2->setMaximum(99999);
        height2->setValue(300);
        pix2 = new QComboBox(TestRGBClass);
        pix2->addItem(QString());
        pix2->addItem(QString());
        pix2->addItem(QString());
        pix2->addItem(QString());
        pix2->setObjectName(QString::fromUtf8("pix2"));
        pix2->setGeometry(QRect(370, 480, 121, 21));
        open2 = new QPushButton(TestRGBClass);
        open2->setObjectName(QString::fromUtf8("open2"));
        open2->setGeometry(QRect(520, 480, 80, 20));
        width2 = new QSpinBox(TestRGBClass);
        width2->setObjectName(QString::fromUtf8("width2"));
        width2->setGeometry(QRect(370, 510, 121, 21));
        width2->setMinimum(1);
        width2->setMaximum(99999);
        width2->setValue(400);
        set_fps2 = new QSpinBox(TestRGBClass);
        set_fps2->setObjectName(QString::fromUtf8("set_fps2"));
        set_fps2->setGeometry(QRect(370, 570, 121, 21));
        set_fps2->setMinimum(1);
        set_fps2->setMaximum(300);
        set_fps2->setValue(25);
        fps1 = new QLabel(TestRGBClass);
        fps1->setObjectName(QString::fromUtf8("fps1"));
        fps1->setGeometry(QRect(10, 150, 54, 12));
        fps1->setStyleSheet(QString::fromUtf8("color: rgb(170, 7, 50);"));
        fps2 = new QLabel(TestRGBClass);
        fps2->setObjectName(QString::fromUtf8("fps2"));
        fps2->setGeometry(QRect(370, 150, 54, 12));
        fps2->setStyleSheet(QString::fromUtf8("color: rgb(255, 10, 83);"));

        retranslateUi(TestRGBClass);
        QObject::connect(open1, SIGNAL(clicked()), TestRGBClass, SLOT(Open1()));
        QObject::connect(open2, SIGNAL(clicked()), TestRGBClass, SLOT(Open2()));

        QMetaObject::connectSlotsByName(TestRGBClass);
    } // setupUi

    void retranslateUi(QWidget *TestRGBClass)
    {
        TestRGBClass->setWindowTitle(QCoreApplication::translate("TestRGBClass", "TestRGB", nullptr));
        video1->setText(QCoreApplication::translate("TestRGBClass", "video", nullptr));
        video2->setText(QCoreApplication::translate("TestRGBClass", "video", nullptr));
        open1->setText(QCoreApplication::translate("TestRGBClass", "Open", nullptr));
        pix1->setItemText(0, QCoreApplication::translate("TestRGBClass", "YUV420P", nullptr));
        pix1->setItemText(1, QCoreApplication::translate("TestRGBClass", "RGBA", nullptr));
        pix1->setItemText(2, QCoreApplication::translate("TestRGBClass", "ARGB", nullptr));
        pix1->setItemText(3, QCoreApplication::translate("TestRGBClass", "BGRA", nullptr));

        pix2->setItemText(0, QCoreApplication::translate("TestRGBClass", "YUV420P", nullptr));
        pix2->setItemText(1, QCoreApplication::translate("TestRGBClass", "RGBA", nullptr));
        pix2->setItemText(2, QCoreApplication::translate("TestRGBClass", "ARGB", nullptr));
        pix2->setItemText(3, QCoreApplication::translate("TestRGBClass", "BGRA", nullptr));

        open2->setText(QCoreApplication::translate("TestRGBClass", "Open", nullptr));
        fps1->setText(QCoreApplication::translate("TestRGBClass", "FPS:", nullptr));
        fps2->setText(QCoreApplication::translate("TestRGBClass", "FPS:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestRGBClass: public Ui_TestRGBClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTRGB_H
