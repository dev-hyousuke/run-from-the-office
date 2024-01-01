#include "UIManager.h"

void UIManager::DrawTimer(int remainingTime)
{
    int borderWidth = 2;
    DrawText(("Time: " + std::to_string(remainingTime)).c_str(), 10 - borderWidth, 10 - borderWidth, 20, BLACK);    
    DrawText(("Time: " + std::to_string(remainingTime)).c_str(), 10 + borderWidth, 10 - borderWidth, 20, BLACK);
    DrawText(("Time: " + std::to_string(remainingTime)).c_str(), 10 - borderWidth, 10 + borderWidth, 20, BLACK);
    DrawText(("Time: " + std::to_string(remainingTime)).c_str(), 10 + borderWidth, 10 + borderWidth, 20, BLACK);

    DrawText(("Time: " + std::to_string(remainingTime)).c_str(), 10, 10, 20, WHITE);
}

void UIManager::DrawGameOver(int windowWidth, int windowHeight)
{
    const char* message = "Game Over!";
    int fontSize = 100;
    int textWidth = MeasureText(message, fontSize);
    int textHeight = fontSize;

    int textX = (windowWidth - textWidth) / 2; 
    int textY = (windowHeight - textHeight) / 2;

    int borderWidth = 2;
    DrawText(message, textX - borderWidth, textY - borderWidth, fontSize, BLACK);
    DrawText(message, textX + borderWidth, textY - borderWidth, fontSize, BLACK);
    DrawText(message, textX - borderWidth, textY + borderWidth, fontSize, BLACK);
    DrawText(message, textX + borderWidth, textY + borderWidth, fontSize, BLACK);

    DrawText(message, textX, textY, fontSize, RED);
}