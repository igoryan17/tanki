//
// Created by igoryan on 18.04.15.
//

#include "CTexture.h"
#include <cassert>

const std::string RenderNull = "Error render is nullptr";

CTexture::CTexture(std::string path, SDL_Renderer *render, int flag) {
    if (render) {
        mTexture = CTexture::LoadTexture(path, render, flag);
    }
    else {
        mTexture = nullptr;
        std::cout << RenderNull << std::endl;
    }
}

CTexture::CTexture(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize,
                   SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr) {
        mTexture = nullptr;
        CMyErrorShow::show_error("TTF_OpenFont");
    }
    else {
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
        if (surf == nullptr) {
            TTF_CloseFont(font);
            mTexture = nullptr;
            CMyErrorShow::show_error("TTF_RenderText_Blended");
        }
        else {
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
            if (texture == nullptr) {
                CMyErrorShow::show_error("SDL_CreateTextureFromSurface");
            }
            mTexture = texture;
            SDL_FreeSurface(surf);
            TTF_CloseFont(font);
        }
    }
}

void CTexture::RenderTexture(SDL_Renderer *ren, int x, int y) {
    assert(x >= 0 && y >= 0);
    if (ren == nullptr) {
        std::cout << RenderNull << std::endl;
        return;
    }
    if (mTexture == nullptr) {
        std::cout << "Error mTexture null" << std::endl;
        return;
    }
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    if (SDL_QueryTexture(mTexture, NULL, NULL, &dst.w, &dst.h) != 0) {
        CMyErrorShow::show_error("SDL_QueryTexture");
    }
    if (SDL_RenderCopy(ren, mTexture, NULL, &dst) != 0) {
        CMyErrorShow::show_error("SDL_RenderCopy");
    }
}

void CTexture::RenderTexture(SDL_Renderer *ren, int x, int y, int w, int h) {
    assert(x >= 0 && y >= 0);
    assert(w >= 0 && h >= 0);
    SDL_Rect dst{x, y , w, h};
    if (SDL_RenderCopy(ren, mTexture, NULL, &dst) != 0) {
        CMyErrorShow::show_error("SDL_RenderCopy");
    }
}

CTexture::~CTexture() {
    std::cout << "~CTexture" << std::endl;
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
    }
}