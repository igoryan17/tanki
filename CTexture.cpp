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