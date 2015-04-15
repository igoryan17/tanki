//
// Created by igoryan on 15.04.15.
//

#ifndef TANKS_CWINDOW_H
#define TANKS_CWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <bits/stringfwd.h>

class CWindow {
protected:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    SDL_Window *mWindow = nullptr;
    SDL_Surface *mScreen = nullptr;
    SDL_Renderer *mRender = nullptr;
public:
    CWindow();
    CWindow(std::string title, int Width, int Height, Uint32 flags);
    CWindow(std::string title, int x, int y, int width, int height, Uint32 flags);
    virtual ~CWindow();
};


#endif //TANKS_CWINDOW_H
