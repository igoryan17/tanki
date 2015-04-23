//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_CTANKBODY_H
#define TANKI_CTANKBODY_H

#include "CTexture.h"
#include <SDL2/SDL.h>
#include "CWindow.h"

class CTankBody : public CTexture {
protected:
    SDL_Point mTopLeft;
    SDL_Point mDownLeft;
    SDL_Point mTopRight;
    SDL_Point mCenterForTower;
    const std::string mPath = "tanks/";
    const std::string mGreen = "Tank_Green_Body.png";
    SDL_Color mColor = {55, 55, 55, 1};
    SDL_Point mDownRight = {0, 0};
    double mAngel = 3 * M_PI / 2;
    SDL_Point mRes;
    SDL_Point mSpeed;
    SDL_Point mSpeedUp;
    unsigned short int mModulSpeed = 3;
    unsigned short int mModulSpeedUp = 1;
public:
    CTankBody(SDL_Renderer *ren, SDL_Point res);

    CTankBody(SDL_Point spawn, SDL_Renderer *ren);

    void GoForward();

    void GoBack();

    void Render(SDL_Renderer *ren) {
        RenderTexture(ren, mDownRight.x, mDownRight.y);
    }

    virtual ~CTankBody();
};

#endif //TANKI_CTANKBODY_H
