//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_CTANKBODY_H
#define TANKI_CTANKBODY_H

#include "coordinats.h"
#include "CTexture.h"

class CTankBody {
protected:
    coordinate mTopLeft;
    coordinate mDownLeft;
    coordinate mTopRight;
    coordinate mDownRight;
    coordinate mCenterForTower;
    CTexture* mTexture = nullptr;
    const std::string mPath = "tanks/";
    const std::string mGreen = "normal_Tank_Green.png";
public:
    CTankBody(SDL_Renderer *ren) {}
};


#endif //TANKI_CTANKBODY_H
