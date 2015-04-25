//
// Created by igoryan on 18.04.15.
//

#ifndef TANKI_CTEXTURE_H
#define TANKI_CTEXTURE_H


#include <SDL2/SDL_render.h>
#include "CLoadMedia.h"
#include "CMyErrorShow.h"
#include "cleanup.h"

enum type {
    BMP,
    JPG,
    PNG
};

class CTexture {
protected:
        SDL_Texture *mTexture = nullptr;
        int mWidth;
        int mHeight;
        SDL_Renderer *mRen;
public:
    friend class CMenu;

    CTexture() {}

    ~CTexture();

    CTexture(std::string path, SDL_Renderer *render, int flag);

    CTexture(std::string path, SDL_Renderer *render, int flag, SDL_Color color);

    CTexture(const std::string &message, const std::string &fontFile,
             SDL_Color color, int fontSize, SDL_Renderer *renderer);

    void RenderTexture(SDL_Renderer *ren, int x, int y);

    void RenderTexture(int x, int y, SDL_Rect* clip = NULL, float angle = 0.0, SDL_Point* center = NULL,
                       SDL_RendererFlip flip = SDL_FLIP_NONE);

    void RenderTexture(SDL_Renderer *ren, int x, int y, int w, int h);

    SDL_Texture *LoadTexture(std::string path, SDL_Renderer *render, int flag) {
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
                std::cout << "Error load flag\n";
                return nullptr;
        }
        if (Load == nullptr)
            return nullptr;
        std::cout << "mWidth:" << mWidth << " mHeight:" << mHeight << std::endl;
        SDL_Texture *Texture_ret = SDL_CreateTextureFromSurface(render, Load);
        SDL_FreeSurface(Load);
        if (Texture_ret == nullptr) {
            CMyErrorShow::show_error("SDL_CreateTextureFromSurface");
        }
        return Texture_ret;
    }

    static SDL_Surface* LoadSurface(std::string & path, int flag) {
        switch (flag) {
            case BMP:
                return CLoadMedia::LoadBMP(path);
            case JPG:
                return CLoadMedia::LoadJPG(path);
            case PNG:
                return CLoadMedia::LoadPNG(path);
            default:
                std::cout << "couldn't load surface" << std::endl;
                return nullptr;
        }
    }
};

#endif //TANKI_CTEXTURE_H
