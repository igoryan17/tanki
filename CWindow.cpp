//
// Created by igoryan on 15.04.15.
//

#include "CWindow.h"

CWindow::CWindow() : SCREEN_WIDTH(640), SCREEN_HEIGHT(480) {
    mWindow = SDL_CreateWindow("no name", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show_error("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
    }
}

CWindow::CWindow(std::string title, int Width, int Height, Uint32 flags) : SCREEN_WIDTH(Width), SCREEN_HEIGHT(Height) {
    mWindow = SDL_CreateWindow(title.c_str(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show_error("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
    }
}

CWindow::CWindow(std::string title, int x, int y, int width, int height, Uint32 flags) :
        SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {
    mWindow = SDL_CreateWindow(title.c_str(), x, y, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (mWindow == nullptr) {
        CMyErrorShow::show_error("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show_error("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRender == nullptr) {
        CMyErrorShow::show_error("SDL_CreateRenderer");
    }
}

CWindow::~CWindow() {

}