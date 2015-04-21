//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"

CMenu::CMenu(int x, int y, resolution &res, Uint32 flags) : CWindow(x, y, res,flags) {
    CTexture *mBackground = new CTexture(mPathToBackground, mRender, JPG);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    mBackground->RenderTexture(mRender, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    mMutexRender.unlock();
    DrawMenu();
}

void CMenu::DrawMenu() {
    for (int i = 0; i < count; i++) {
        int y = (int) (50 * Scale + i * 40 * Scale);
        mTextsMenu[i] = new Ctext(mTexts[i], mFontPath, mColor, mTextSize, mRender);
        mTextsMenu[i]->RenderTexture(mRender, SCREEN_WIDTH / 2, y);
        SDL_QueryTexture(mTextsMenu[i]->mTexture, NULL, NULL, &mTexturesData[i].W, &mTexturesData[i].H);
        mTexturesData[i].X = SCREEN_WIDTH / 2;
        mTexturesData[i].Y = y;
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
        if (mTexturesData[i].X <= x && x <= (mTexturesData[i].X + mTexturesData[i].W) &&
                mTexturesData[i].Y <= y && y <= (mTexturesData[i].Y + mTexturesData[i].H))
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