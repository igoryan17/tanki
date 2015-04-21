//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_CTANKBODY_H
#define TANKI_CTANKBODY_H

#include "coordinats.h"
#include "CTexture.h"
#include <SDL2/SDL.h>
#include "MyColor.h"
#include "CWindow.h"

class CTankBody : public CTexture {
protected:
    coordinate mTopLeft;
    coordinate mDownLeft;
    coordinate mTopRight;
    coordinate mCenterForTower;
    const std::string mPath = "tanks/";
    const std::string mGreen = "Tank_Green_Body.png";
    MyColor mColor = {55, 55, 55, 1};
    resolution mRes;
public:
    CTankBody(SDL_Renderer *ren, resolution res);

    coordinate mDownRight = {0, 0};

    void GoForward() {
        if (mDownRight.y < mRes.Height) {
            mDownRight.y += 1;
        }
    }

    void GoBack() {
        if (mDownRight.y > 0) {
            mDownRight.y -= 1;
        }
    }

    void Render(SDL_Renderer *ren) {
        RenderTexture(ren, mDownRight.x, mDownRight.y);
    }

    virtual ~CTankBody();
};


#endif //TANKI_CTANKBODY_H
