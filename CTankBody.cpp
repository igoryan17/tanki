//
// Created by igoryan on 20.04.15.
//

#include "CTankBody.h"

CTankBody::CTankBody(SDL_Renderer *ren) :
        mPath("tanks/"), mGreen("Tank_Green_Body.png"),
        mColor(55, 55, 55, 1),
        CTexture("tanks/Tank_Green_Body.png", ren, PNG, mColor.color) {
    if (!mTexture) {
        std::cout << "Pizda" << std::endl;
    }
}

CTankBody::~CTankBody() {
    std::cout << "~CTankBody" << std::endl;
}