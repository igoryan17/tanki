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
#include "Ctext.h"
#include "coordinats.h"
#include "CTankBody.h"

class CTexture;
class Ctext;
class CTankBody;

enum Menu {
        play,
        options,
        credits,
        exit_game,
        count
    };



class CMenu : public CWindow {
private:
    CTexture *mBackground = nullptr;
    const std::string mGameName = "316 Panzers";
    const std::string mFontPath = "Text/Comfortaa_Bold.ttf";
    const SDL_Color mColor = {168, 12, 12, 1};
    const int mTextSize = (int const) (32 * Scale);
    const std::string mPathToBackground = "menu_images/menu_background.jpg";
    const std::string mTexts[count] = {"play", "options", "credits", "exit"};
    Ctext* mTextsMenu[count];
    TextureSize mTexturesData[count];
    std::mutex mMutexRender;
    CTankBody *mTankBody;

public:
    CMenu(resolution &res);

    CMenu(int x, int y, resolution &res, Uint32 flags);

    virtual ~CMenu();

    void DrawMenu();

    int ProcessingMouseCoordinat(int x, int y);

    void OnMenu(SDL_Event &Event);

    friend class CApp;
};

#endif //TANKS_CMENU_H
