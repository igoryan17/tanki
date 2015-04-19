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
    ChooseScreenResolution();
    if (mResolution.Width > 0 && mResolution.Height > 0) {
        mMenu = new CMenu(0, 0, mResolution, SDL_WINDOW_SHOWN);
    }
    else {
        mMenu = new CMenu(mResolution);
    }
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

void CApp::OnMenu() {
    //turn on music
    /*
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(50);
    Mix_Music *tap = Mix_LoadMUS("sound/Wot_menu.wav");
    if (tap == nullptr) {
        std::cout << "Error Mix_LoadMUS:" << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(tap, 1);
     */
    SDL_Delay(3000);
    mRunning = false;
}

void CApp::CallEngine() {
    if (mFlagThread) {
        mEngine = new MyThread(&CApp::OnMenu, this);
    }
    else {
        OnMenu();
    }
}

void CApp::join() {
    mEngine->join();
}

void CApp::ShowRender() {
    assert(mMenu != nullptr);
    assert(mMenu->mRender != nullptr);
    while (mRunning) {
        while (SDL_PollEvent(&mEvent) != 0) {
            if (mEvent.type == SDL_QUIT) {
                SDL_Quit();
            }
            SDL_RenderPresent(mMenu->mRender);
            SDL_Delay(30);
        }
    }
}

CApp::~CApp() {
    std::cout << "~CApp" << std::endl;
    delete mEngine;
    delete mMenu;
}

int main(int argc, char *argv[]) {
    CApp TheApp(argc, argv);
    TheApp.CallEngine();
    TheApp.ShowRender();
    TheApp.join();
    return 0;
}