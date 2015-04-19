//
// Created by igoryan on 18.04.15.
//

#ifndef TANKI_CLEANUP_H
#define TANKI_CLEANUP_H

#include <utility>
#include <SDL2/SDL.h>
/*
template<typename T, typename... Args>
void cleanup(T *t, Args&&... args){
    //Cleanup the first item in the list
    cleanup(t);
    //Clean up the remaining arguments
    cleanup(std::forward<Args>(args)...);
}

template<>
void cleanup<SDL_Window>(SDL_Window *win){
    if (!win){
        return;
    }
    SDL_DestroyWindow(win);
}
template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren){
    if (!ren){
        return;
    }
    SDL_DestroyRenderer(ren);
}
template<>
void cleanup<SDL_Texture>(SDL_Texture *tex){
    if (!tex){
        return;
    }
    SDL_DestroyTexture(tex);
}
template<>
void cleanup<SDL_Surface>(SDL_Surface *surf){
    if (!surf){
        return;
    }
    SDL_FreeSurface(surf);
}
*/
#endif//TANKI_CLEANUP_H
