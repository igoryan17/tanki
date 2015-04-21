//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <cstring>
#include <cassert>

CApp::CApp(resolution &res) :
        mResolution(res),
        CMenu(0, 0, res, SDL_WINDOW_SHOWN) {
    mTankBody = new CTankBody(mRender, mResolution);
    mRunning = true;
}

void CApp::ShowRender() {
    while (mRunning) {
        mMutexRender.lock();
        SDL_RenderPresent(mRender);
        mMutexRender.unlock();
    }
}

void CApp::GPU() {
    OnMenu(mEvent);
}

void CApp::CallGPU() {
    if (mFlagThread) {
        mGPU = new MyThread(&CApp::ShowRender, this);
    }
    else {
        GPU();
    }
}

void CApp::join() {
    mGPU->join();
}

void CApp::Engine() {
    assert(mRender != nullptr);
    CallGPU();
    while (mRunning) {
        while (SDL_PollEvent(&mEvent) != 0) {
            if (mEvent.type == SDL_QUIT) {
                SDL_Quit();
                SDL_RenderClear(mRender);
                mRunning = false;
                return;
            }
            switch (mEvent.key.keysym.sym) {
                case SDLK_UP:
                    mTankBody->GoForward();
                    break;
                case SDLK_w:
                    mTankBody->GoForward();
                    break;
                case SDLK_DOWN:
                    mTankBody->GoBack();
                    break;
                case SDLK_s:
                    mTankBody->GoBack();
                    break;
                default:
                    break;
            }
            mMutexRender.lock();
            SDL_RenderClear(mRender);
            mTankBody->Render(mRender);
            SDL_RenderPresent(mRender);
            mMutexRender.unlock();
        }
    }
    SDL_Quit();
}

CApp::~CApp() {
    std::cout << "~CApp" << std::endl;
    while (mRunning);
    if (mGPU)
        delete mGPU;
    if (mTankBody)
        delete mTankBody;
}

resolution ChooseResolution(const int &argc, const char** argv);

int main(int argc, char *argv[]) {
    resolution res = ChooseResolution(argc, (char const **) argv);
    CApp TheApp(res);
    TheApp.Engine();
    TheApp.join();
    return 0;
}

resolution ChooseResolution(const int &argc, const char** argv) {
    SDL_DisplayMode mode;
    resolution res;
    if (argc == 2) {
        if (SDL_GetCurrentDisplayMode(0, &mode) != 0) {
            CMyErrorShow::show_error("SDL_GetCurrentDisplayMode");
            return res;
        }
    }
    char *ptr = nullptr;
    switch (argc) {
        case 1:
            return res;
        case 2:
            if (strcmp("-f", argv[1]) != 0) {
                std::cout << "doesn't know parametr:" << argv[1] << std::endl;
                return res;
            }
            res.Width = static_cast<unsigned int>(mode.w);
            res.Height = static_cast<unsigned int>(mode.h);
            return res;
        case 3:
            if (strcmp("-u", argv[1]) != 0) {
                std::cout << "doesn't know parametr:" << argv[1] << std::endl;
            }
            res.Width = static_cast<unsigned int>(atoi(argv[2]));
            ptr = (char *) strchr(argv[2], 'x');
            if (ptr == nullptr) {
                res.Width = 0;
                res.Height = 0;
                return res;
            }
            res.Height = static_cast<unsigned int>(atoi(ptr));
            return res;
        default:
            res.Width = 0;
            res.Height = 0;
            return res;
    }
}