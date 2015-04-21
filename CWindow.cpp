//
// Created by igoryan on 15.04.15.
//

#include "CWindow.h"
#include "CMyErrorShow.h"
#include "CInitResources.h"

CWindow::CWindow(int x, int y, resolution &res, Uint32 flags) :
        mRatio(4 / 3), mEpsilon(0.000001) {
    CInitResources::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    CInitResources::IMG(IMG_INIT_JPG);
    CInitResources::TTF();
    if (res.Width == 0 && res.Height == 0) {
        SCREEN_WIDTH = 800;
        SCREEN_HEIGHT = 600;
    }
    else {
        InitializationResolutions();
        SetResolution(res.Width, res.Height);
    }
    res.Width = SCREEN_WIDTH;
    res.Height = SCREEN_HEIGHT;
    mWindow = SDL_CreateWindow("316 panzers", x, y, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
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
    resolution res;

    res.Width = 640;
    res.Height = 480;
    mResolutions.push_back(res);

    res.Width = 800;
    res.Height = 600;
    mResolutions.push_back(res);

    res.Width = 1024;
    res.Height = 768;
    mResolutions.push_back(res);

    res.Width = 1152;
    res.Height = 864;
    mResolutions.push_back(res);

    res.Width = 1280;
    res.Height = 960;
    mResolutions.push_back(res);

    res.Width = 1400;
    res.Height = 1050;
    mResolutions.push_back(res);

    res.Width = 1600;
    res.Height = 1200;
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
    std::vector<resolution>::iterator i;
    for (i = mResolutions.begin(); i < mResolutions.end(); i++) {
        if (w >= (*i).Width && h >= (*i).Height) {
            SCREEN_WIDTH = (*i).Width;
            SCREEN_HEIGHT = (*i).Height;
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