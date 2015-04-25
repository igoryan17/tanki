//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_CTANKBODY_H
#define TANKI_CTANKBODY_H

#include "CTexture.h"
#include <SDL2/SDL.h>
#include <thread>
#include "CWindow.h"
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

const int N = 2;

typedef boost::numeric::ublas::c_vector<float, N> Vector;

class CTankBody : public CTexture {
protected:
    SDL_Point mTopLeft;
    SDL_Point mDownLeft;
    SDL_Point mTopRight;
    SDL_Point mCenter;
    const std::string mPath = "tanks/";
    const std::string mGreen = "Tank_Green_Body.png";
    SDL_Color mColor = {55, 55, 55, 1};
    SDL_Point mDownRight = {0, 0};
    double mAngel = 3 * M_PI / 2;
    SDL_Point mRes;
    SDL_Point mSpeed;
    SDL_Point mSpeedUp;
    unsigned short int mModulSpeed = 10;
    unsigned short int mModulSpeedUp = 1;
    float mEpsilon = 0.3;
    std::thread mThread;
    bool &mRunning;
    Vector mDirection;
public:
    CTankBody(SDL_Point spawn, SDL_Renderer *ren, SDL_Point res, bool &running);

    void GoForward();

    float ModulVector(const SDL_Point& Vector) {
        return (float)sqrt(pow(Vector.x, 2) + pow(Vector.y, 2));
    }

    void GoBack();

    void Render(SDL_Renderer *ren) {
        RenderTexture(mCenter.x, mCenter.y, nullptr, (double) mAngel, nullptr, SDL_FLIP_NONE);
    }

    std::thread CallMoving() {
        return std::thread(&CTankBody::moving, this);
    }

    void left() {
        mAngel+=3;
    }

    void right() {
        mAngel-=3;
    }

    void moving();

    virtual ~CTankBody();
};

#endif //TANKI_CTANKBODY_H
