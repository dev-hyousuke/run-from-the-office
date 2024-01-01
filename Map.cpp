#include "Map.h"
#include "raymath.h"

void Map::DrawMap(Vector2 playerWorldPosition, int windowWidth, int windowHeight)
{
    DrawRectangle(0.0, 0.0, windowWidth, windowHeight, BLACK);
    mapPosition = Vector2Scale(playerWorldPosition, -1.f);
    DrawTextureEx(texture, mapPosition, 0.0, mapScale, WHITE);
}