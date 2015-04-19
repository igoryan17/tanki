//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <cstring>
#include <cassert>

CApp::CApp(int argc, char **argv) : mArgc(argc), mArgv(argv) {
    mRunning = true;
    CInitResources::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    CInitResources::IMG(IMG_INIT_JPG);
    CInitResources::TTF();
    ChooseScreenResolution();
    if (mResolution.Width > 0 && mResolution.Height > 0) {
        mMenu = new CMenu(0, 0, mResolution, SDL_WINDOW_SHOWN);
    }
    else {
        mMenu = new CMenu(mResolution);
    }
    mRender = mMenu->mRender;
}

void CApp::ChooseScreenResolution() {
    SDL_DisplayMode mode;
    if (mArgc == 2) {
        if (SDL_GetCurrentDisplayMode(0, &mode) != 0) {
            CMyErrorShow::show_error("SDL_GetCurrentDisplayMode");
            return;
        }
    }
    char *ptr = nullptr;
    switch (mArgc) {
        case 1:
            return;
        case 2:
            if (strcmp("-f", mArgv[1]) != 0) {
                std::cout << "doesn't know parametr:" << mArgv[1] << std::endl;
                return;
            }
            mResolution.Width = static_cast<unsigned int>(mode.w);
            mResolution.Height = static_cast<unsigned int>(mode.h);
            return;
        case 3:
            if (strcmp("-u", mArgv[1]) != 0) {
                std::cout << "doesn't know parametr:" << mArgv[1] << std::endl;
            }
            mResolution.Width = static_cast<unsigned int>(atoi(mArgv[2]));
            ptr = strchr(mArgv[2], 'x');
            if (ptr == nullptr) {
                mResolution.Width = 0;
                mResolution.Height = 0;
                return;
            }
            mResolution.Height = static_cast<unsigned int>(atoi(ptr));
            return;
        default:
            mResolution.Width = 0;
            mResolution.Height = 0;
            return;
    }
}

void CApp::Engine() {
    assert(mMenu != nullptr);
    mMenu->OnMenu(mEvent);
}

void CApp::CallEngine() {
    if (mFlagThread) {
        mEngine = new MyThread(&CApp::Engine, this);
    }
    else {
        Engine();
    }
}

void CApp::join() {
    mEngine->join();
}

void CApp::ShowRender() {
    assert(mMenu != nullptr);
    assert(mRender != nullptr);
    SDL_PollEvent(&mEvent);
        if (mEvent.type == SDL_QUIT) {
            SDL_Quit();
            SDL_RenderClear(mRender);
            mRunning = false;
            return;
        }
        else {
            CallEngine();
        }
    while (mRunning) {
        while (SDL_PollEvent(&mEvent) != 0) {
            if (mEvent.type == SDL_QUIT) {
                SDL_Quit();
                SDL_RenderClear(mRender);
                mRunning = false;
                return;
            }
            SDL_RenderPresent(mRender);
            SDL_Delay(30);
        }
    }
    SDL_Quit();
}

CApp::~CApp() {
    std::cout << "~CApp" << std::endl;
    while (mRunning);
    delete mEngine;
    delete mMenu;
}

int main(int argc, char *argv[]) {
    CApp TheApp(argc, argv);
    TheApp.ShowRender();
    TheApp.join();
    return 0;
}