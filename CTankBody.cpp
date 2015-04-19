//
// Created by igoryan on 20.04.15.
//

#include "CTankBody.h"

CTankBody::CTankBody(SDL_Renderer *ren) {
    mTexture = new CTexture(mPath + mGreen, ren, PNG);
}