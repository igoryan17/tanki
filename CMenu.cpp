//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include "CLoadMedia.h"

CMenu::CMenu() : CWindow() {
    mTextMenu[new_game] = "New Game";
    mTextMenu[out] = "out";
    mPathToBackground = "menu_background.jpg";
    SDL_Surface *loaded = CLoadMedia::LoadJPG(mPathToBackground);
    SDL_Texture *mBackground = SDL_CreateTextureFromSurface(mRender, loaded);
    SDL_FreeSurface(loaded);
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, mBackground, NULL, NULL);
}

CMenu::~CMenu() {

}

void CMenu::show_window() {
    SDL_RenderPresent(mRender);
}

#include "CWindow.cpp"