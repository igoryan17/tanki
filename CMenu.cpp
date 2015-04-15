//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"
#include "CLoadMedia.h"

CMenu::CMenu() : CWindow() {
    mTextMenu[new_game] = "New Game";
    mTextMenu[out] = "out";
    mPathToBackground = "menu_background.jpg";
    SDL_BlitSurface(CLoadMedia::LoadJPG(mPathToBackground), mScreen, )
}