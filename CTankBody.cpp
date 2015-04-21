//
// Created by igoryan on 20.04.15.
//

#include "CTankBody.h"

CTankBody::CTankBody(SDL_Renderer *ren, resolution res) :
        CTexture("tanks/Tank_Green_Body.png", ren, PNG, {55, 55, 55, 1}),
        mRes(res) {
    std::cout << mColor << std::endl;
    if (!mTexture) {
        std::cout << "Pizda" << std::endl;
    }
}

CTankBody::~CTankBody() {
    std::cout << "~CTankBody" << std::endl;
}