//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CINITRESOURCES_H
#define TANKI_CINITRESOURCES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CMyErrorShow.h"

enum MyFlag {
    not_init = false,
    init = true
};

class CInitResources {
private:
    static MyFlag mSDL;
    static MyFlag mIMG;
public:
    CInitResources();

    static void SDL(Uint32 flags) {
        if (SDL_Init(flags) < 0) {
            CMyErrorShow::show_error("SDL_Init");
        }
        else {
            mSDL = init;
        }
    }

    static void IMG(int flags) {
        if (!(IMG_Init(flags) & flags)) {
            CMyErrorShow::show_error("IMG_Init");
        }
        else {
            mIMG = init;
        }
    }
};

MyFlag CInitResources::mSDL = not_init;
MyFlag CInitResources::mIMG = not_init;

#endif //TANKS_CINITRESOURCES_H
