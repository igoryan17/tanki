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

typedef std::thread MyThread;
class CApp {
private:
    bool mRunning = false;
    bool mFlagThread = true;
    CMenu *mMenu = nullptr;
    float mScale = 1;
    resolution mResolution;
    static MyThread *mGPU;
    static MyThread *mEngine;
public:
    int mArgc;
    char** mArgv;
    CApp();
    ~CApp();
    void waitMenuCreate() {
        while(mMenu == nullptr);
        while(mMenu->mRender == nullptr);
    }
    void OnMenu();
    void ChooseScreenResolution();
    void CallEngine();
    void CallGPU();
    void join();
    friend class CMenu;
};

MyThread* CApp::mGPU = nullptr;
MyThread* CApp::mEngine = nullptr;
#endif //SDL_EXAMPLES_CAPP_H