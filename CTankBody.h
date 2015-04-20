//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_CTANKBODY_H
#define TANKI_CTANKBODY_H

#include "coordinats.h"
#include "CTexture.h"
#include <SDL2/SDL.h>
#include "MyColor.h"

class CTankBody : public CTexture {
protected:
    coordinate mTopLeft;
    coordinate mDownLeft;
    coordinate mTopRight;
    coordinate mDownRight;
    coordinate mCenterForTower;
    const std::string mPath;
    const std::string mGreen;
    const MyColor mColor;
public:
    CTankBody(SDL_Renderer *ren);

    virtual ~CTankBody();
};


#endif //TANKI_CTANKBODY_H
