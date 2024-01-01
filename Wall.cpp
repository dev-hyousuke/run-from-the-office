#include "Wall.h"

Wall::Wall(Vector2 position, int width, int height) : 
    worldPosition(position), 
    width(width), 
    height(height) 
{}

void Wall::Render(Vector2 playerPosition)
{
    Vector2 screenPosition = Vector2Subtract(worldPosition, playerPosition);
    DrawRectangle(screenPosition.x, screenPosition.y, width, height, RED);
}

Rectangle Wall::GetCollisonRectangle(Vector2 playerPosition)
{
    Vector2 screenPosition = Vector2Subtract(worldPosition, playerPosition);
    return Rectangle{
        screenPosition.x,
        screenPosition.y,
        static_cast<float>(width),
        static_cast<float>(height)
    };
}