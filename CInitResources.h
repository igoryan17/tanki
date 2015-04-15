//
// Created by igoryan on 15.04.15.
//

#ifndef TANKS_CINITRESOURCES_H
#define TANKS_CINITRESOURCES_H

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
        if (IMG_Init(flags) & flags != flags) {
            std::cout << "Error IMG_Init:" << IMG_GetError() << std::endl;
        }
        else {
            mIMG = init;
        }
    }

    static void IMG(int flags) {
        if (SDL_Init(flags) != 0) {
            std::cout << "Error SDL_Init:" << SDL_GetError() << std::endl;
        }
        else {
            mSDL = init;
        }
    }
};

MyFlag CInitResources::mSDL = not_init;
MyFlag CInitResources::mIMG = not_init;

#endif //TANKS_CINITRESOURCES_H
