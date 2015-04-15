//
// Created by igoryan on 15.04.15.
//
#include "CInitResources.h"
#include "CMyErrorShow.h"

void CInitResources::SDL(Uint32 flags) {
    SDL_Init(flags) != 0 ? CMyErrorShow::show("SDL_Init") :
    mSDL = init;
}

void CInitResources::IMG(int flags) {
    IMG_Init(flags)&flags !=flags ? CMyErrorShow::show("IMG_Init") :
    mIMG = init;
}
