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
#include "CApp.h"

struct resolution {
    unsigned int Width;
    unsigned int Height;
    resolution() : Width(0), Height(0) {}
    resolution(unsigned int W, unsigned int H) : Width(W), Height(H) {}
    resolution(const resolution & obj) {
        Width = obj.Width;
        Height = obj.Height;
    }
    friend std::ostream& operator<< (std::ostream& os, const resolution res);
};
std::ostream& operator<< (std::ostream& os, const resolution res) {
    os << res.Width << "x" << res.Height;
    return os;
}

class CWindow {
protected:
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    SDL_Window *mWindow = nullptr;
    SDL_Surface *mScreen = nullptr;
    SDL_Renderer *mRender = nullptr;
    const float mRatio;
    const float mEpsilon;
private:
    std::vector<resolution> mResolutions;
public:
    void InitializationResolutions();
    void SetResolution(unsigned int w, unsigned int h);
    CWindow();
    CWindow(std::string title, int Width, int Height, Uint32 flags);
    CWindow(std::string title, int x, int y, int width, int height, Uint32 flags);
    virtual ~CWindow();
};


#endif //TANKS_CWINDOW_H
