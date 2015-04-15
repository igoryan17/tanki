//
// Created by igoryan on 15.04.15.
//

#ifndef TANKS_CLOADMEDIA_H
#define TANKS_CLOADMEDIA_H


#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CLoadMedia {
public:
    CLoadMedia() {}
    static SDL_Surface *LoadJPG();
    static SDL_Surface *LoadPNG();
    static SDL_Surface *LoadBMP();
private:
};


#endif //TANKS_CLOADMEDIA_H
