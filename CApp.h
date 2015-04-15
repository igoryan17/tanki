//
// Created by igoryan on 15.04.15.
//

#ifndef SDL_EXAMPLES_CAPP_H
#define SDL_EXAMPLES_CAPP_H

#include <SDL2/SDL.h>
#include "CMenu.h"

class CApp {
private:
    bool mRunning = false;
    CMenu mMenu;
public:
    CApp();

    void OnMenu();
};


#endif //SDL_EXAMPLES_CAPP_H
