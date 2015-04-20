//
// Created by igoryan on 19.04.15.
//

#ifndef TANKI_CTEXT_H
#define TANKI_CTEXT_H

#include <iostream>
#include <string>
#include "CTexture.h"

class Ctext : public CTexture {
private:
public:
    Ctext(std::string message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

    virtual ~Ctext();

    friend class CMenu;
};

#endif //TANKI_CTEXT_H
