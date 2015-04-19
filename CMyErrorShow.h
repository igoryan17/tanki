//
// Created by igoryan on 15.04.15.
//

#ifndef TANKI_CMYERRORSHOW_H
#define TANKI_CMYERRORSHOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <iostream>

class CMyErrorShow {
public:
    static void show_error(std::string name_function) {
        const std::string err = "Error " + name_function + ":";
        if (name_function.find("SDL") != std::string::npos) {
            std::cout << err << SDL_GetError() << std::endl;
        }

        if (name_function.find("IMG") != std::string::npos) {
            std::cout << err << SDL_GetError() << std::endl;
        }

        if (name_function.find("Mix") != std::string::npos) {
            std::cout << err << SDL_GetError() << std::endl;
        }
        if (name_function.find("TTF") != std::string::npos) {
            std::cout << err << SDL_GetError() << std::endl;
        }
    }
};

#endif //TANKS_CMYERRORSHOW_H
