//
// Created by igoryan on 20.04.15.
//

#include "CTankBody.h"

CTankBody::CTankBody(SDL_Renderer *ren, SDL_Point res) :
        CTexture("tanks/Tank_Green_Body.png", ren, PNG, {55, 55, 55, 1}),
        mRes(res) {
    std::cout << "R:" << mColor.r << "G:" << mColor.g << "B:" << mColor.b << "A:" << mColor.a << std::endl;
    if (!mTexture) {
        std::cout << "Pizda" << std::endl;
    }
}

void CTankBody::GoForward() {
    mSpeed = {0, mModulSpeed};
    mSpeedUp = {0, -mModulSpeedUp};
    auto ModulSpeed = [this]() -> float {
        return (float) sqrt(pow(mSpeed.x, 2) + pow(mSpeed.y, 2));
    };
    float epsilon = 0.7;
    while (ModulSpeed() > epsilon) {
        mDownRight.x += mSpeed.x;
        mDownRight.y += mSpeed.y;
        mSpeed.x += mSpeedUp.x;
        mSpeed.y += mSpeedUp.y;
    }
}

void CTankBody::GoBack() {

}

CTankBody::~CTankBody() {
    std::cout << "~CTankBody" << std::endl;
}