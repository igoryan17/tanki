//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CINITRESOURCES_H
#define TANKI_CINITRESOURCES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "CMyErrorShow.h"

enum MyFlag {
    not_init = false,
    init = true
};

class CInitResources {
private:
public:
    CInitResources() {
    }

    static MyFlag SDL(Uint32 flags) {
        if (SDL_Init(flags) < 0) {
            CMyErrorShow::show_error("SDL_Init");
            return not_init;
        }
        else {
            return init;
        }
    }

    static MyFlag IMG(int flags) {
        if (!(IMG_Init(flags) & flags)) {
            CMyErrorShow::show_error("IMG_Init");
            return  not_init;
        }
        else {
            return init;
        }
    }
    static MyFlag TTF() {
        if (TTF_Init() != 0) {
            CMyErrorShow::show_error("TTF_Init");
            return not_init;
        }
        else {
            return init;
        }
    }
    ~CInitResources() {}
};

#endif //TANKS_CINITRESOURCES_H
