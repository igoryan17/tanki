//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CAPP_H
#define TANKI_CAPP_H

#include <SDL2/SDL.h>
#include "CMenu.h"

class CApp {
private:
    bool mRunning = false;
    CMenu *mMenu = nullptr;
    float mScale = 1;
public:
    CApp();
    ~CApp();
    void OnMenu(int width, int height);
};


#endif //SDL_EXAMPLES_CAPP_H
