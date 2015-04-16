//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CLOADMEDIA_H
#define TANKI_CLOADMEDIA_H


#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CInitResources.h"
#include <iostream>

class CLoadMedia {
public:
    CLoadMedia() {}

    static SDL_Surface *LoadJPG(std::string path) {
        CInitResources::IMG(IMG_INIT_JPG);
        SDL_Surface *loadedSurface = IMG_Load(path.c_str());
        if (loadedSurface == nullptr) {
            CMyErrorShow::show_error("IMG_Load");
        }
        return loadedSurface;
    }

    static SDL_Surface *LoadPNG(std::string path) {
        CInitResources::IMG(IMG_INIT_PNG);
        SDL_Surface *loadedSurface = IMG_Load(path.c_str());
        if (loadedSurface == nullptr) {
            CMyErrorShow::show_error("IMG_Load");
        }
        return loadedSurface;
    }
    static SDL_Surface *LoadBMP(std::string path) {
        SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
        if (loadedSurface == nullptr) {
            CMyErrorShow::show_error("SDL_LoadBMP");
        }
        return loadedSurface;
    }
private:
};


#endif //TANKS_CLOADMEDIA_H
