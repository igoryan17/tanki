//
// Created by igoryan on 15.04.15.
//

#ifndef TANKS_CMENU_H
#define TANKS_CMENU_H

#include <SDL2/SDL.h>
#include <iostream>
#include "CWindow.h"

class CMenu : public CWindow {
private:
    enum Menu{
        new_game,
        out
    };
    std::string mTextMenu[out];
    std::string mGameName;
    std::string mPathToBackground;
public:
    CMenu();
    void show_window();
    virtual ~CMenu();
};


#endif //TANKS_CMENU_H
