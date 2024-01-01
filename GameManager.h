#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <iostream>
#include "Raylib.h"

class GameManager
{
    public:
        GameManager();
        int GetWindowWidth() { return windowWidth; }
        int GetWindowHeight() { return windowHeight; }
    private:
        int windowWidth{1280};
        int windowHeight{720};
        const char* title{"Run From The Office!"};
};

#endif