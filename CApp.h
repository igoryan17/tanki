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
#include "CTankBody.h"

typedef std::thread MyThread;

class CApp : public CMenu {
private:
    bool mRunning = false;
    bool mFlagThread = true;
    SDL_Point &mResolution;
    SDL_Event mEvent;
    static MyThread *mGPU;
    CTankBody *mTankBody = nullptr;
public:
    CApp(SDL_Point &res);

    virtual ~CApp();

    void GPU();

    void CallGPU();

    void ShowRender();

    void join();

    void Engine();
};

MyThread *CApp::mGPU = nullptr;
#endif //SDL_EXAMPLES_CAPP_H