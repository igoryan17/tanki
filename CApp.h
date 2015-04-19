//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CAPP_H
#define TANKI_CAPP_H

#include <SDL2/SDL.h>
#include "CMenu.h"
#include <SDL2/SDL_thread.h>
#include <thread>
#include <mutex>
#include "CWindow.h"

typedef std::thread MyThread;

class CApp {
private:
    bool mRunning = false;
    bool mFlagThread = true;
    CMenu *mMenu = nullptr;
    SDL_Renderer *mRender;
    resolution mResolution;
    SDL_Event mEvent;
    static MyThread *mEngine;
    int mArgc = 1;
    char **mArgv = nullptr;
public:
    CApp(int argc, char **argv);

    ~CApp();

    void OnMenu();

    void ChooseScreenResolution();

    void CallEngine();

    void join();

    void ShowRender();

    friend class CMenu;
};

MyThread *CApp::mEngine = nullptr;
#endif //SDL_EXAMPLES_CAPP_H