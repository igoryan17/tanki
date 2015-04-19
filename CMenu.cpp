//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include <cassert>

CMenu::CMenu(resolution &res) : CWindow(res) {
    mPathToBackground = "menu_images/menu_background.jpg";
    mBackground = new CTexture(mPathToBackground, mRender, JPG);
    assert(mBackground != nullptr);
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

CMenu::CMenu(int x, int y, resolution &res, Uint32 flags) : CWindow(x, y, res, flags) {
    mPathToBackground = "menu_images/menu_background.jpg";
    CTexture *mBackground = new CTexture(mPathToBackground, mRender, JPG);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    mMutexRender.unlock();
}

CMenu::~CMenu() {
    std::cout << "~CMenu" << std::endl;
    if (mBackground) {
        std::cout << "Clear Texture" << std::endl;
        delete mBackground;
    }
}