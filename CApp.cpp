//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <cstdlib>
#include <cstring>
#include <SDL2/SDL_video.h>

CApp::CApp() {
    mRunning = true;
    CInitResources::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    CInitResources::IMG(IMG_INIT_JPG);
}

void CApp::ChooseScreenResolution() {
    resolution res;
    SDL_DisplayMode mode;
    if (mArgc == 2) {
        if (SDL_GetCurrentDisplayMode(0, &mode) != 0) {
            CMyErrorShow::show_error("SDL_GetCurrentDisplayMode");
            mResolution = res;
            return;
        }
    }
    char *ptr = nullptr;
    switch(mArgc) {
        case 1:
            res.Width = 640;
            res.Height = 480;
            mResolution = res;
            return;
        case 2:
            if (strcmp("-f", mArgv[1]) != 0) {
                std::cout << "doesn't know parametr:" << mArgv[1] << std::endl;
                mResolution = res;
                return;
            }
            res.Width = mode.w;
            res.Height = mode.h;
            mResolution = res;
            return;
        case 3:
            if (strcmp("-u", mArgv[1]) != 0) {
                std::cout << "doesn't know parametr:" << mArgv[1] << std::endl;
            }
            res.Width = atoi(mArgv[2]);
            ptr = strchr(mArgv[2], 'x');
            if (ptr == nullptr) {
                res.Width = 0;
                res.Height = 0;
                mResolution = res;
                return;
            }
            res.Height = atoi(ptr);
            mResolution = res;
            return;
        default:
            res.Width = 0;
            res.Height = 0;
            mResolution = res;
            return;
    }
}

void CApp::OnMenu() {
    resolution res = mResolution;
    if (res.Width > 0 && res.Height > 0) {
        mMenu = new CMenu(0, 0, res.Width, res.Height, SDL_WINDOW_SHOWN);
        mScale = (float) res.Height / 480;
        std::cout << "Scale:" << mScale << std::endl;
    }
    else {
        mMenu = new CMenu();
    }
    //turn on music
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(50);
    Mix_Music *tap = Mix_LoadMUS("sound/Wot_menu.wav");
    if (tap == nullptr) {
        std::cout << "Error Mix_LoadMUS:" << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(tap, 1);
    //end initialization music
    SDL_Event Event;
    while (mRunning) {
        mMenu->mMutexRender.lock();
        while (SDL_PollEvent(&Event) != 0) {
            if (Event.type == SDL_QUIT) {
                mRunning = false;
                SDL_DestroyRenderer(mMenu->mRender);
            }
        }
        mMenu->mMutexRender.unlock();
    }
}

void CApp::CallGPU() {
    std::thread *GPU = new std::thread(std::bind(&CMenu::show_window, mMenu));
    mGPU = GPU;
}

void CApp::CallEngine() {
    std::thread *Engine = new std::thread(std::bind(&CApp::OnMenu, this));
    mEngine = Engine;
}

void CApp::join() {
    mEngine->join();
    mGPU->join();
}

CApp::~CApp() {
    delete mMenu;
}

int main(int argc, char *argv[]) {
    CApp TheApp;
    TheApp.mArgc = argc;
    TheApp.mArgv = argv;
    TheApp.ChooseScreenResolution();
    TheApp.CallEngine();
    TheApp.waitMenuCreate();
    TheApp.CallGPU();
    TheApp.join();
    return 0;
}

#include "CMenu.cpp"