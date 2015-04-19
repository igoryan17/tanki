//
// Created by igoryan on 19.04.15.
//

#ifndef TANKI_CTEXT_H
#define TANKI_CTEXT_H

#include <iostream>
#include <string>
#include "CTexture.h"

class Ctext {
private:
    CTexture *mText = nullptr;
public:
    Ctext(std::string message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

    void render(SDL_Renderer *ren, int x, int y);

    bool CheckPosition(const int & x, const int & y);

    ~Ctext();

    friend class CMenu;
};

#endif //TANKI_CTEXT_H
