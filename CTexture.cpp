//
// Created by igoryan on 18.04.15.
//

#include "CTexture.h"

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
    if (ren == nullptr) {
        std::cout << RenderNull << std::endl;
        return;
    }
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(mTexture, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(ren, mTexture, NULL, &dst);
}

CTexture::~CTexture() {
    SDL_DestroyTexture(mTexture);
}