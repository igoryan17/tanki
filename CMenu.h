//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CMENU_H
#define TANKI_CMENU_H

#include <SDL2/SDL.h>
#include <iostream>
#include "CWindow.h"
#include "CLoadMedia.h"
#include <mutex>
#include "CTexture.h"

class CMenu : public CWindow {
private:
    enum Menu {
        play = 0,
        options = 1,
        credits = 2,
        exit = 3,
        count = 4
    };
    CTexture *mBackground = nullptr;
    std::string mGameName = "316 Panzers";
    std::string mPathToBackground;
    std::string mTexts[count] = {"play", "options", "creits", "exit"};
    std::mutex mMutexRender;
public:
    CMenu(resolution & res);
    CMenu(int x, int y, resolution &res, Uint32 flags);
    virtual ~CMenu();
    friend class CApp;
};

#endif //TANKS_CMENU_H
