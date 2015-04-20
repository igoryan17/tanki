//
// Created by igoryan on 19.04.15.
//

#include "Ctext.h"

Ctext::Ctext(std::string message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) :
            CTexture(message, fontFile, color, fontSize, renderer) {
}

Ctext::~Ctext() {
    std::cout << "~Ctext" << std::endl;
}