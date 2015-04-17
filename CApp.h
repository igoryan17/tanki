//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CAPP_H
#define TANKI_CAPP_H

#include <SDL2/SDL.h>
#include "CMenu.h"
#include <SDL2/SDL_thread.h>
#include <thread>

typedef SDL_Thread MyThread;
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
    static void ThreadGPU(void* data) {
        CMenu *ptr = static_cast<CMenu*>(data);
        return ptr->show_window();
    }
    static void ThreadEngine(void* data) {
        CApp *ptr = static_cast<CApp*>(data);
        return ptr->OnMenu();
    }
    void wait();
    void join();
};

MyThread* CApp::mGPU = nullptr;
MyThread* CApp::mEngine = nullptr;
#endif //SDL_EXAMPLES_CAPP_H