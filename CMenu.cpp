//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include "CLoadMedia.h"

CMenu::CMenu() {
    CWindow();
    mTextMenu[new_game] = "New Game";
    mTextMenu[out] = "out";
    mPathToBackground = "menu_background.jpg";
    SDL_Texture *background = SDL_CreateTextureFromSurface(mRender, CLoadMedia::LoadJPG(mPathToBackground));
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, background, NULL, NULL);
}

CMenu::~CMenu() {

}