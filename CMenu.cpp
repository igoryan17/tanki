//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"

CMenu::CMenu(SDL_Point &res, Uint32 flags) : CWindow(res, flags) {
    CTexture *mBackground = new CTexture(mPathToBackground, mRender, JPG);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    mMutexRender.unlock();
    DrawMenu();
}

void CMenu::DrawMenu() {
    for (int i = 0; i < count; i++) {
        int y = (int) (50 * mScaleY + i * 40 * mScaleY);
        mTextsMenu[i] = new Ctext(mTexts[i], mFontPath, mColor, mTextSize, mRender);
        mTextsMenu[i]->RenderTexture(mRender, SCREEN_WIDTH / 2, y);
        SDL_QueryTexture(mTextsMenu[i]->mTexture, NULL, NULL, &mTexturesData[i].x, &mTexturesData[i].y);
        mTexturesData[i].x = SCREEN_WIDTH / 2;
        mTexturesData[i].y = y;
    }
}

void CMenu::OnMenu(SDL_Event &Event) {
    std::cout << "OnMenu" << std::endl;
    int xMousePosition;
    int yMousePosition;
}

int CMenu::ProcessingMouseCoordinat(int x, int y) {
    //std::cout << "x:" << x << " y:" << y << std::endl;
    for (int i = 0; i < count; i++) {
        bool lies = false;
        //std::cout << mTexturesData[i] << std::endl << std::endl;
        if (mTexturesData[i].x <= x && x <= (mTexturesData[i].x + mTexturesData[i].x) &&
                mTexturesData[i].y <= y && y <= (mTexturesData[i].y + mTexturesData[i].y))
            lies = true;
        //std::cout << "lies:" << lies << std::endl;
        if (lies) {
            return i;
        }
    }
    return count;
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