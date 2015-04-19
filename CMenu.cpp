//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include <cassert>

CMenu::CMenu(resolution &res) : CWindow(res) {
    mBackground = new CTexture(mPathToBackground, mRender, JPG);
    assert(mBackground != nullptr);
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int i = 0; i < count; i++) {
        mTextsMenu[i] = new Ctext(mTexts[i], mFontPath, mColor, mTextSize, mRender);
        mTextsMenu[i]->render(mRender, SCREEN_WIDTH / 2, (int) (50 * Scale + i * 40 * Scale));
    }
}

CMenu::CMenu(int x, int y, resolution &res, Uint32 flags) : CWindow(x, y, res, flags) {
    CTexture *mBackground = new CTexture(mPathToBackground, mRender, JPG);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    mMutexRender.unlock();
}

void CMenu::OnMenu(SDL_Event &Event) {
    std::cout << "OnMenu" << std::endl;
    int xMousePosition;
    int yMousePosition;
    while (1) {
        if (Event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&xMousePosition, &yMousePosition);
        }
    }
}

CMenu::~CMenu() {
    std::cout << "~CMenu" << std::endl;
    if (mBackground) {
        std::cout << "Clear Texture" << std::endl;
        delete mBackground;
    }
    for (int i = 0; i < count; i++) {
        if (mTextsMenu[i] != nullptr) {
            delete mTextsMenu[i];
        }
    }
}