#include "GameManager.h"

GameManager::GameManager()
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
}