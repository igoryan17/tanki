//
// Created by igoryan on 20.04.15.
//

#ifndef TANKI_MYCOLOR_H
#define TANKI_MYCOLOR_H

#include <SDL2/SDL.h>

struct MyColor {
    SDL_Color color;
    MyColor() {}
    MyColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }

    MyColor(const MyColor &obj) {
        color.r = obj.color.r;
        color.g = obj.color.g;
        color.b = obj.color.b;
        color.a = obj.color.a;
    }

    friend std::ostream& operator<<(std::ostream & os, const MyColor &obj);
};

inline std::ostream& operator<<(std::ostream & os, const MyColor &obj) {
    return os << "R:" << obj.color.r << " G:" << obj.color.g << " B:" << obj.color.b << " A:" << obj.color.a;
}
#endif //TANKI_MYCOLOR_H
