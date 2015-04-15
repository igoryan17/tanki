//
// Created by igoryan on 15.04.15.
//

CWindow::CWindow() : SCREEN_WIDTH(640), SCREEN_HEIGHT(480) {
    mWindow = SDL_CreateWindow("no name", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (mWindow == nullptr) {
        CMyErrorShow::show("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show("SDL_CreateRenderer");
    }
}

CWindow::CWindow(std::string title, int Width, int Height, Uint32 flags) : SCREEN_WIDTH(Width), SCREEN_HEIGHT(Height) {
    mWindow = SDL_CreateWindow(title, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (mWindow == nullptr) {
        CMyErrorShow::show("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show("SDL_CreateRenderer");
    }
}

CWindow::CWindow(std::string title, int x, int y, int width, int height, Uint32 flags) :
        SCREEN_WIDTH(Width), SCREEN_HEIGHT(Height) {
    mWindow = SDL_CreateWindow(title, x, y, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (mWindow == nullptr) {
        CMyErrorShow::show("SDL_CreateWindow");
    }

    mScreen = SDL_GetWindowSurface(mWindow);
    if (mScreen == nullptr) {
        CMyErrorShow::show("SDL_GetWindowSurface");
    }

    mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRender == nullptr) {
        CMyErrorShow::show("SDL_CreateRenderer");
    }
}

CWindow::~CWindow() {

}