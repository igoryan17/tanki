//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_COORDINATS_H
#define TANKI_COORDINATS_H

#include <iostream>

struct coordinate {
    int x = 0;
    int y = 0;
    coordinate (int x, int y) : x(x), y(y) {}
    coordinate() : x(0), y(0) {}
    coordinate (const coordinate & obj) {
        x = obj.x;
        y = obj.y;
    }
    friend std::ostream& operator<<(std::ostream & os, const coordinate & obj);
};

inline std::ostream& operator<<(std::ostream & os, const coordinate & obj) {
    return os << "x:" << obj.x << " y:" << obj.y;
}

struct TextureSize {
    int W = 0;
    int H = 0;
    int X = 0;
    int Y = 0;
    TextureSize () {}
    TextureSize (int w, int h, int x, int y) : W(w), H(h), X(x), Y(y) {}
    TextureSize (const TextureSize & obj) {
        W = obj.W;
        H = obj.H;
        X = obj.X;
        Y = obj.Y;
    }
    friend std::ostream& operator<<(std::ostream & os, const TextureSize & obj);
};

inline std::ostream& operator<<(std::ostream & os, const TextureSize & obj) {
    os << "W:" << obj.W << " H:" << obj.H << "\n";
    os << "X:" << obj.X << " Y:" << obj.Y;
    return os;
}

#endif //TANKI_COORDINATS_H
