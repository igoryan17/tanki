//
// Created by igoryan on 15.04.15.
//

#include "CWindow.h"
#include "CMyErrorShow.h"
#include "CInitResources.h"

CWindow::CWindow(SDL_Point &res, Uint32 flags) :
        mRatio(4 / 3), mEpsilon(0.000001) {
    CInitResources::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    CInitResources::IMG(IMG_INIT_JPG);
    CInitResources::TTF();
    if (res.x == 0 && res.y == 0) {
        SCREEN_WIDTH = 800;
        SCREEN_HEIGHT = 600;
    }
    else {
        InitializationResolutions();
        SetResolution(res.x, res.y);
    }
    res.x = SCREEN_WIDTH;
    res.y = SCREEN_HEIGHT;
    mWindow = SDL_CreateWindow("316 panzers",
                               mLeftUpWindowAngle.x,
                               mLeftUpWindowAngle.y,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               flags);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
        SDL_Quit();
    }

    Scale = (float) fabs((float)SCREEN_WIDTH / 800);
    std::cout << "Scale:" << Scale << std::endl;

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }
}

void CWindow::InitializationResolutions() {
    SDL_Point res;

    res.x = 640;
    res.y = 480;
    mResolutions.push_back(res);

    res.x = 800;
    res.y = 600;
    mResolutions.push_back(res);

    res.x = 1024;
    res.y = 768;
    mResolutions.push_back(res);

    res.x = 1152;
    res.y = 864;
    mResolutions.push_back(res);

    res.x = 1280;
    res.y = 960;
    mResolutions.push_back(res);

    res.x = 1400;
    res.y = 1050;
    mResolutions.push_back(res);

    res.x = 1600;
    res.y = 1200;
    mResolutions.push_back(res);
}

void CWindow::SetResolution(unsigned int w, unsigned int h) {
    auto print_resolution = [this] {
        std::cout << this->SCREEN_WIDTH << "x" << this->SCREEN_HEIGHT << std::endl;
    };
    if (w == 0 && h == 0) {
        SCREEN_WIDTH = 640;
        SCREEN_HEIGHT = 480;
        print_resolution();
        return;
    }
    if (fabs((float) w / (float) h - mRatio) < mEpsilon) {
        SCREEN_WIDTH = w;
        SCREEN_HEIGHT = h;
        print_resolution();
        return;
    }
    std::vector<SDL_Point>::iterator i;
    for (i = mResolutions.begin(); i < mResolutions.end(); i++) {
        if (w >= (*i).x && h >= (*i).y) {
            SCREEN_WIDTH = (unsigned int) (*i).x;
            SCREEN_HEIGHT = (unsigned int) (*i).y;
        }
        else {
            i = mResolutions.end();
        }
    }
    print_resolution();
}

CWindow::~CWindow() {
    std::cout << "~CWindow" << std::endl;
    SDL_DestroyRenderer(mRender);
    SDL_DestroyWindow(mWindow);
}