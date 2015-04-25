//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <cstring>
#include <cassert>

CApp::CApp(SDL_Point &res) :
        mResolution(res),
        CMenu(res, SDL_WINDOW_SHOWN) {
    SDL_Point SpawnTank = {100, 100};
    mTankBody = new CTankBody(SpawnTank, mRender, res, mRunning);
    mRunning = true;
}

void CApp::ShowRender() {
    mMutexRender.lock();
    std::cout << "GPU mRender:" << mRender << std::endl;
    mMutexRender.unlock();
    while (mRunning) {
        SDL_GetMouseState(&mMousePosition.x, &mMousePosition.y);
        while (SDL_PollEvent(&mEvent)) {
            SDL_Keycode KeyTemp = mEvent.key.keysym.sym;
            mKey.push(KeyTemp);
            Uint32 TypeTemp = mEvent.type;
            if (TypeTemp == SDL_QUIT) {
                mType.push(TypeTemp);
            }
            SDL_RenderPresent(mRender);
            SDL_RenderClear(mRender);
            mTankBody->Render(mRender);
            SDL_Delay(10);
        }
    }
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

void CApp::Engine() {
    assert(mRender != nullptr);
    mMutexRender.lock();
    std::cout << "Engine mRender:" << mRender << std::endl;
    mMutexRender.unlock();
    while (mRunning) {
        if (mType.size() > 0) {
            if (mType.front() == SDL_QUIT) {
                SDL_Quit();
                mType.pop();
                SDL_RenderClear(mRender);
                mRunning = false;
                return;
            }
            else {
                mType.pop();
            }
        }
        if (mKey.size() > 0) {
            switch (mKey.front()) {
                case SDLK_UP:
                    mKey.pop();
                    mTankBody->GoForward();
                    break;
                case SDLK_w:
                    mKey.pop();
                    mTankBody->GoForward();
                    break;
                case SDLK_DOWN:
                    mKey.pop();
                    mTankBody->GoBack();
                    break;
                case SDLK_s:
                    mKey.pop();
                    mTankBody->GoBack();
                    break;
                case SDLK_a:
                    mTankBody->left();
                    break;
                case SDLK_d:
                    mTankBody->right();
                    break;
                default:
                    mKey.pop();
                    break;
            }
        }
    }
    SDL_Quit();
}

CApp::~CApp() {
    std::cout << "~CApp" << std::endl;
    while (mRunning);
    if (mEngine)
        delete mEngine;
    if (mTankBody)
        delete mTankBody;
}

SDL_Point ChooseResolution(const int &argc, const char **argv);

int main(int argc, char *argv[]) {
    SDL_Point res = ChooseResolution(argc, (char const **) argv);
    CApp TheApp(res);
    TheApp.CallEngine();
    TheApp.ShowRender();
    TheApp.join();
    return 0;
}

SDL_Point ChooseResolution(const int &argc, const char **argv) {
    SDL_DisplayMode mode;
    SDL_Point res = {0, 0};
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
            res.x = static_cast<unsigned int>(mode.w);
            res.y = static_cast<unsigned int>(mode.h);
            return res;
        case 3:
            if (strcmp("-u", argv[1]) != 0) {
                std::cout << "doesn't know parametr:" << argv[1] << std::endl;
            }
            res.x = static_cast<unsigned int>(atoi(argv[2]));
            ptr = (char *) strchr(argv[2], 'x');
            if (ptr == nullptr) {
                res.x = 0;
                res.y = 0;
                return res;
            }
            res.y = static_cast<unsigned int>(atoi(ptr));
            return res;
        default:
            res.x = 0;
            res.y = 0;
            return res;
    }
}