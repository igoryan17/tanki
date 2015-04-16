//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"

CApp::CApp() {
    mRunning = true;
    CInitResources::SDL(SDL_INIT_VIDEO);
    CInitResources::IMG(IMG_INIT_JPG);
    mMenu = new CMenu();
}

void CApp::OnMenu() {
    SDL_Event Event;
    while (mRunning) {
        while (SDL_PollEvent(&Event) !=0) {
            if (Event.type == SDL_QUIT) {
                mRunning = false;
            }
            mMenu->show_window();
        }
    }
}

CApp::~CApp() {
    delete mMenu;
}

int main(int argc, char *argv[]) {
    CApp TheApp;
    TheApp.OnMenu();
    return 0;
}

#include "CMenu.cpp"