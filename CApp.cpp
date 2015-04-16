//
// Created by igoryan on 15.04.15.
//

#include "CApp.h"
#include <iostream>
#include <vector>
#include <SDL2/SDL_video.h>

CApp::CApp() {
    mRunning = true;
    CInitResources::SDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    CInitResources::IMG(IMG_INIT_JPG);
}

void CApp::OnMenu(int width, int height) {
    if (width > 0 && height > 0) {
        mMenu = new CMenu(0, 0, width, height, SDL_WINDOW_SHOWN);
        mScale = (float) height / 480;
        std::cout << "Scale:" << mScale << std::endl;
    }
    else {
        mMenu = new CMenu();
    }
    //turn on music
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(50);
    Mix_Music *tap = Mix_LoadMUS("sound/Wot_menu.wav");
    if (tap == nullptr) {
        std::cout << "Error Mix_LoadMUS:" << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(tap, 1);
    //end initialization music
    SDL_Event Event;
    while (mRunning) {
        while (SDL_PollEvent(&Event) != 0) {
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
    // see user arguments
    auto lambda = [](int width, int height) -> void {
        std::cout << "Width:" << width << " Height:" << height << std::endl;
    };
    const float W = 4.0;
    const float H = 3.0;
    enum screen_resolution {
        Width = 0,
        Height = 1,
        Count = 2
    };
    struct resolution {
        int res[Count];
    };
    std::vector<resolution> resolutions;
    resolution res;

    res.res[Width] = 800;
    res.res[Height] = 600;
    resolutions.push_back(res);

    res.res[Width] = 1024;
    res.res[Height] = 768;
    resolutions.push_back(res);

    res.res[Width] = 1152;
    res.res[Height] = 864;
    resolutions.push_back(res);

    res.res[Width] = 1280;
    res.res[Height] = 960;
    resolutions.push_back(res);

    res.res[Width] = 1400;
    res.res[Height] = 1050;
    resolutions.push_back(res);

    res.res[Width] = 1600;
    res.res[Height] = 1200;
    resolutions.push_back(res);

    std::vector<resolution>::iterator i = resolutions.begin();
    const float aspect_ratio = W / H;
    float epsilon = 0.0000001;
    int width = 0;
    int height = 0;
    switch (argc) {
        case 1:
            TheApp.OnMenu(0, 0);
            break;
        case 2:
            if (strcmp(argv[1], "-f") != 0) {
                return 1;
            }
            SDL_DisplayMode mode;
            if (SDL_GetCurrentDisplayMode(0, &mode) != 0) {
                CMyErrorShow::show_error("SDL_GetCurrentDisplayMode");
                return 1;
            }
            for (i = resolutions.begin(); i < resolutions.end(); i++) {
                if ((*i).res[Width] <= mode.w && (*i).res[Height] <= mode.h) {
                    width = (*i).res[Width];
                    height = (*i).res[Height];
                }
                else {
                    i = resolutions.end();
                }
            }
            lambda(width, height);
            TheApp.OnMenu(width, height);
            break;
        case 4:
            width = atoi(argv[1]);
            if (width == 0) {
                std::cout << "Error read width" << std::endl;
                TheApp.OnMenu(0, 0);
                break;
            }
            if (strcmp(argv[2], "x") != 0) {
                std::cout << "Error read symbol 'x'" << std::endl;
                lambda(640, 480);
                TheApp.OnMenu(0, 0);
                break;
            }
            height = atoi(argv[3]);
            if (height == 0) {
                std::cout << "Error read height" << std::endl;
                lambda(640, 480);
                TheApp.OnMenu(0, 0);
                break;
            }
            if ((((float) width / (float) height) - aspect_ratio) < epsilon) {
                lambda(width, height);
                TheApp.OnMenu(width, height);
            }
            else {
                std::cout << "Error choose screen ratio must be" << W << "/" << H << std::endl;
                lambda(640, 480);
                TheApp.OnMenu(0, 0);
                break;
            }
            break;
        default:
            lambda(640, 480);
            TheApp.OnMenu(0, 0);
    }
    return 0;
}

#include "CMenu.cpp"