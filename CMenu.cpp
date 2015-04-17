//
// Created by igoryan on 15.04.15.
//

#include "CMenu.h"

CMenu::CMenu() : CWindow() {
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Surface *loaded = CLoadMedia::LoadJPG(mPathToBackground);
    SDL_Texture *mBackground = SDL_CreateTextureFromSurface(mRender, loaded);
    SDL_FreeSurface(loaded);
    SDL_RenderClear(mRender);
    mMutexRender.lock();
    SDL_RenderCopy(mRender, mBackground, NULL, NULL);
    mMutexRender.unlock();
}

CMenu::CMenu(int x, int y, int width, int height, Uint32 flags) : CWindow("316 panzers",
                                                                          x,
                                                                          y,
                                                                          width,
                                                                          height,
                                                                          flags) {
    mPathToBackground = "menu_images/menu_background.jpg";
    SDL_Surface *loaded = CLoadMedia::LoadJPG(mPathToBackground);
    SDL_Texture *mBackground = SDL_CreateTextureFromSurface(mRender, loaded);
    SDL_FreeSurface(loaded);
    mMutexRender.lock();
    SDL_RenderClear(mRender);
    SDL_RenderCopy(mRender, mBackground, NULL, NULL);
    mMutexRender.unlock();
}

void CMenu::show_window() {
    while(mRender!= nullptr) {
        SDL_RenderCopy(mRender, mBackground, NULL, NULL);
        SDL_RenderPresent(mRender);
        SDL_Delay(700);
    }
}

CMenu::~CMenu() {

}

#include "CWindow.cpp"