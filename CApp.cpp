//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "CInitResources.h"

CApp::CApp() {
    mRunning = true;
    CInitResources::IMG(IMG_INIT_JPG);
    CInitResources::SDL(SDL_INIT_VIDEO);
}

void CApp::OnMenu() {

}

int main() {
    CApp TheApp;
    TheApp.OnMenu();
}