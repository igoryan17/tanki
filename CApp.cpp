//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <cstring>

CApp::CApp() {
    mRunning = true;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_JPG);
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
    if (mResolution.Width > 0 && mResolution.Height > 0) {
        mMenu = new CMenu(0, 0, mResolution.Width, mResolution.Height, SDL_WINDOW_SHOWN);
    }
    else {
        mMenu = new CMenu();
    }
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
    //end initialization music
    while(!mMenu->mFlagGPU);
    CallGPU();
    SDL_Event Event;
    while (mRunning) {
        while (SDL_PollEvent(&Event) != 0) {
            if (Event.type == SDL_QUIT) {
                std::cout << "Exit\n";
                mRunning = false;
                mMenu->mFlagGPU = false;
            }
        }
    }
}

void CApp::CallGPU() {
    if (mFlagThread) {
        mGPU = new MyThread(&CMenu::show, mMenu);
    }
    else {
        mMenu->show();
    }
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
    mGPU->join();
}

CApp::~CApp() {
    SDL_Quit();
    delete mMenu;
}

int main(int argc, char *argv[]) {
    CApp TheApp;
    TheApp.mArgc = argc;
    TheApp.mArgv = argv;
    TheApp.ChooseScreenResolution();
    TheApp.CallEngine();
    TheApp.join();
    return 0;
}