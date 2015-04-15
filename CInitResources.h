//
// Created by igoryan on 15.04.15.
//

#ifndef TANKS_CINITRESOURCES_H
#define TANKS_CINITRESOURCES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CInitResources {
private:
    enum flags {
        not_init = false,
        init = true
    };
    static flags mSDL = not_init;
    static flags mIMG = not_init;
public:
    CInitResources() {}
    static void SDL(Uint32 flags);
    static void IMG(int flags);
};


#endif //TANKS_CINITRESOURCES_H
