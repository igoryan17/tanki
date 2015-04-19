//
// Created by igoryan on 19.04.15.
//

#include "Ctext.h"

Ctext::Ctext(std::string message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    mText = new CTexture(message, fontFile, color, fontSize, renderer);
}

void Ctext::render(SDL_Renderer *ren, int x, int y) {
    if (mText == nullptr) {
        return;
    }
    mText->RenderTexture(ren, x, y);
}

Ctext::~Ctext() {
    std::cout << "~Ctext" << std::endl;
    if (mText != nullptr)
        delete mText;
}