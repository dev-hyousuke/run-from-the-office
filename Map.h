#include "Raylib.h"
#include "GameManager.h"

class Map
{
    public:
        void DrawMap(Vector2 playerWorldPosition, int windowWidth, int windowHeight);
    private:
        Texture2D texture{LoadTexture("Textures/Map/tutorial.png")};
        Vector2 mapPosition{0.0, 0.0};
        const float mapScale{4.f};
};