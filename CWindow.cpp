//
// Created by igoryan on 15.04.15.
//

#include <bits/stl_vector.h>
#include "CWindow.h"
#include <cmath>

CWindow::CWindow() : SCREEN_WIDTH(640), SCREEN_HEIGHT(480), mRatio(4 / 3), mEpsilon(0.000001) {
    mWindow = SDL_CreateWindow("316 panzers", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
        SDL_Quit();
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
        cleanup(mWindow);
        SDL_Quit();
    }
}

CWindow::CWindow(std::string title, int Width, int Height, Uint32 flags) : mRatio(4 / 3), mEpsilon(0.000001) {
    InitializationResolutions();
    SetResolution(Width, Height);
    mWindow = SDL_CreateWindow(title.c_str(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
        SDL_Quit();
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
        cleanup(mWindow);
        SDL_Quit();
    }
}

CWindow::CWindow(std::string title, int x, int y, int width, int height, Uint32 flags) :
        mRatio(4 / 3), mEpsilon(0.000001) {
    InitializationResolutions();
    SetResolution(width, height);
    mWindow = SDL_CreateWindow(title.c_str(), x, y, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
        SDL_Quit();
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
        cleanup(mWindow);
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
    auto print_resolution = [this]  {
        std::cout << this->SCREEN_WIDTH << "x" << this->SCREEN_HEIGHT << std::endl;
    };
    if (w == 0 && h == 0) {
        SCREEN_WIDTH = 640;
        SCREEN_HEIGHT = 480;
        print_resolution();
        return;
    }
    if (fabs((float)w / (float)h - mRatio) < mEpsilon) {
        SCREEN_WIDTH = w;
        SCREEN_HEIGHT = h;
        print_resolution();
        return;
    }
    std::vector<resolution>::iterator i = mResolutions.begin();
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
    cleanup(mRender, mWindow);
}