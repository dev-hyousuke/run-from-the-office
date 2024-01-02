#include "raylib.h"
#include "raymath.h"

class Button
{
    public:
        Button(Vector2 position, int width, int height);
        void Render(Vector2 playerPosition);
        Rectangle GetCollisonRectangle(Vector2 playerPosition);
        bool GetWasPressed() { return wasPressed; }
        void SetWasPressed() { wasPressed = true; }
    private:
        Vector2 worldPosition{};
        int width{};
        int height{};
        bool wasPressed{};
};