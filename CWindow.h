//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CWINDOW_H
#define TANKI_CWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <bits/stringfwd.h>
#include <vector>
#include <iostream>
#include "cleanup.h"

class CWindow {
protected:
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    SDL_Window *mWindow = nullptr;
    SDL_Renderer *mRender = nullptr;
    const float mRatio;
    const float mEpsilon;
    const SDL_Point mLeftUpWindowAngle = {0, 0};
private:
    std::vector<SDL_Point> mResolutions;
public:
    void InitializationResolutions();

    void SetResolution(unsigned int w, unsigned int h);

    CWindow(SDL_Point &res, Uint32 flags);

    virtual ~CWindow();

    float Scale = 1.0;
};


#endif //TANKS_CWINDOW_H
