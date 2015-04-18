//
// Created by igoryan on 18.04.15.
//

#ifndef TANKI_CTEXTURE_H
#define TANKI_CTEXTURE_H


#include <SDL2/SDL_render.h>
#include "CLoadMedia.h"
#include "CMyErrorShow.h"

enum type {
    BMP,
    JPG,
    PNG
};
class CTexture {
private:
public:
    static SDL_Texture *LoadTexture(std::string path, int flag, SDL_Renderer *render);
};

SDL_Texture * CTexture::LoadTexture(std::string path, int flag, SDL_Renderer *render) {
    SDL_Surface *Load = nullptr;
    switch (flag) {
        case BMP:
            Load = CLoadMedia::LoadBMP(path);
            break;
        case JPG:
            Load = CLoadMedia::LoadJPG(path);
            break;
        case PNG:
            Load = CLoadMedia::LoadPNG(path);
            break;
        default:
            Load = nullptr;
            std::cout << "Error load flag\n";
            return nullptr;
    }
    SDL_Texture *Texture_ret = SDL_CreateTextureFromSurface(render, Load);
    SDL_FreeSurface(Load);
    if (Texture_ret == nullptr) {
        CMyErrorShow::show_error("SDL_CreateTextureFromSurface");
    }
    return Texture_ret;
}

#endif //TANKI_CTEXTURE_H
