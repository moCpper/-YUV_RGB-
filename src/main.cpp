#include "TestRGB.h"
#include <QtWidgets/QApplication>
extern "C" {
#include<SDL.h>
#include <SDL_main.h>
}
#undef main
#define SDL_MAIN_HANDLED
#pragma comment(lib ,"sdl2.lib")
#pragma comment(lib ,"SDL2main.lib")

int SDL_main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestRGB w;
    w.show();
    return a.exec();
}
