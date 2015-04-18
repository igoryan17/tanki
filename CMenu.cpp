//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"

CMenu::CMenu() : CWindow() {
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Texture *mBackground = CTexture::LoadTexture(mPathToBackground, JPG, mRender);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    if (SDL_RenderCopy(mRender, mBackground, nullptr, nullptr) != 0) {
        CMyErrorShow::show_error("SDL_RenderCopy");
    }
    mMutexRender.unlock();
}

CMenu::CMenu(int x, int y, int width, int height, Uint32 flags) : CWindow("316 panzers",
                                                                          x,
                                                                          y,
                                                                          width,
                                                                          height,
                                                                          flags) {
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Texture *mBackground = CTexture::LoadTexture(mPathToBackground, JPG, mRender);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, mBackground, nullptr, nullptr);
    mMutexRender.unlock();
}

void CMenu::show() {
    while (mRender!= nullptr && mFlagGPU) {
        mMutexRender.lock();
        SDL_RenderPresent(mRender);
        mMutexRender.unlock();
        SDL_Delay(100);
    }
}

CMenu::~CMenu() {
    cleanup(mBackground);
}

#include "CWindow.cpp"