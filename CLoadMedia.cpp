//
// Created by igoryan on 15.04.15.
//

#include <bits/stringfwd.h>
#include "CLoadMedia.h"
#include "CMyErrorShow.h"
#include "CInitResources.h"

SDL_Surface * CLoadMedia::LoadBMP(std::string path) {
    SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr) {
        CMyErrorShow::show_error("SDL_LoadBMP");
    }
    return loadedSurface;
}

SDL_Surface * CLoadMedia::LoadPNG(std::string path) {
    CInitResources::IMG(IMG_INIT_PNG);
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        CMyErrorShow::show_error("IMG_Load");
    }
    return loadedSurface;
}

SDL_Surface * CLoadMedia::LoadJPG(std::string path) {
    CInitResources::IMG(IMG_INIT_JPG);
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        CMyErrorShow::show_error("IMG_Load");
    }
    return loadedSurface;
}