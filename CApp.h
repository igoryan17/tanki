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
#include <queue>

typedef std::thread MyThread;

class CApp : public CMenu {
private:
    bool mRunning = false;
    bool mFlagThread = true;
    SDL_Point &mResolution;
    SDL_Event mEvent;
    static MyThread *mEngine;
    CTankBody *mTankBody = nullptr;
    std::queue<SDL_Keycode> mKey;
    std::queue<Uint32> mType;
    SDL_Point mMousePosition;
public:
    CApp(SDL_Point &res);

    virtual ~CApp();

    void CallEngine();

    void ShowRender();

    void join();

    void Engine();
};

MyThread *CApp::mEngine = nullptr;
#endif //SDL_EXAMPLES_CAPP_H