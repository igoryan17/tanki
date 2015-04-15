//
// Created by igoryan on 15.04.15.
//

#include "CMyErrorShow.h"
#include <iostream>

void CMyErrorShow::show(std::string name_function) {
    if (name_function.find("SDL") != std::string::npos) {
        std::cout << "Error " << name_function << ":" << SDL_GetError() << std::endl;
    }
    if (name_function.find("IMG") != std::string::npos) {
        std::cout << "Error " << name_function << ":" << IMG_GetError() << std::endl;
    }
}