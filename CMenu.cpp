//
// Created by igoryan on 15.04.15.
//

CMenu::CMenu() : CWindow() {
    mTextMenu[new_game] = "New Game";
    mTextMenu[out] = "out";
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Surface *loaded = CLoadMedia::LoadJPG(mPathToBackground);
    SDL_Texture *mBackground = SDL_CreateTextureFromSurface(mRender, loaded);
    SDL_FreeSurface(loaded);
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, mBackground, NULL, NULL);
}

CMenu::CMenu(int x, int y, int width, int height, Uint32 flags) : CWindow("316 panzers",
                                                                          x,
                                                                          y,
                                                                          width,
                                                                          height,
                                                                          flags) {
    mTextMenu[new_game] = "New Game";
    mTextMenu[out] = "out";
    mPathToBackground = "menu_images/menu_background.jpg";
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