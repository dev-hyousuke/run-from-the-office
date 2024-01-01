#include <iostream>
#include "Raylib.h"

class UIManager
{
    public:
        void DrawTimer(int remainingTime);
        void DrawGameOver(int windowWidth, int windowHeight);
};