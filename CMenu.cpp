//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include <cassert>

CMenu::CMenu() : CWindow() {
    mPathToBackground = "menu_images/menu_background.jpg";
    mBackground = new CTexture(mPathToBackground, mRender, JPG);
    assert(mBackground != nullptr);
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0 , 0);
    mFlagGPU = true;
}

CMenu::CMenu(int x, int y, int width, int height, Uint32 flags) : CWindow("316 panzers",
                                                                          x,
                                                                          y,
                                                                          width,
                                                                          height,
                                                                          flags) {
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Texture *mBackground = CTexture::LoadTexture(mPathToBackground, mRender, JPG);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, mBackground, nullptr, nullptr);
    mMutexRender.unlock();
}

void CMenu::show() {
    if (!mFlagGPU) {
        std::cout << "Error show Flag false\n";
    }
    while (mFlagGPU) {
        mMutexRender.lock();
        SDL_RenderPresent(mRender);
        mMutexRender.unlock();
        SDL_Delay(100);
    }
}

CMenu::~CMenu() {
    delete mBackground;
}

