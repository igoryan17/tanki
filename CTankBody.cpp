//
// Created by igoryan on 20.04.15.
//

#include "CTankBody.h"

CTankBody::CTankBody(SDL_Point spawn, SDL_Renderer *ren, SDL_Point res, bool &running) :
        CTexture("tanks/Tank_Green_Body.png", ren, PNG, {55, 55, 55, 1}),
        mRes(res), mRunning(running), mCenter(spawn) {
    std::cout << "R:" << mColor.r << " G:" << mColor.g << " B:" << mColor.b << " A:" << mColor.a << std::endl;
    if (!mTexture) {
        std::cout << "Pizda" << std::endl;
    }
    mAngel = 0;
    mSpeed = {0 ,0};
    mSpeedUp = {0 ,0};
    SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
    mThread = CallMoving();
}

void CTankBody::GoForward() {
    mSpeed.y += mModulSpeed;
    mSpeedUp.y = -mModulSpeedUp;
}

void CTankBody::GoBack() {
    mSpeed.y -= mModulSpeed;
    mSpeedUp.y = mModulSpeedUp;
}

void CTankBody::moving() {
    std::cout << "in moving" << std::endl;
    while (mRunning) {
        Uint32 Delay;
        int temp;
        temp = (int) (mModulSpeed - ModulVector(mSpeed));
        Delay = temp >= 0 ? (Uint32)temp : (Uint32)-temp;
        if (ModulVector(mSpeed) > mEpsilon) {
            if (mSpeed.x > 0) {
                SDL_Delay(Delay);
                mCenter.x++;
            }
            if (mSpeed.x < 0) {
                SDL_Delay(Delay);
                mCenter.x--;
            }
            if (mSpeed.y > 0) {
                if (mCenter.y < mRes.y)
                    mCenter.y++;
                SDL_Delay(Delay);
            }
            if (mSpeed.y < 0) {
                if (mCenter.y > 0)
                    mCenter.y--;
                SDL_Delay(Delay);
            }
            mSpeed.x += mSpeedUp.x;
            mSpeed.y += mSpeedUp.y;
        }
        else {
            SDL_Delay(Delay);
        }
    }
}

CTankBody::~CTankBody() {
    mThread.join();
    std::cout << "~CTankBody" << std::endl;
}