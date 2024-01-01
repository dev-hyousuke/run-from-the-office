#include "raylib.h"
#include "raymath.h"

class Wall
{
    public:
        Wall(Vector2 position, int width, int height);
        void Render(Vector2 playerPosition);
        Rectangle GetCollisonRectangle(Vector2 playerPosition);
    private:
        Vector2 worldPosition{};
        int width{};
        int height{};
};