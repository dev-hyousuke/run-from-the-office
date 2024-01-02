#include "raylib.h"
#include <iostream>
#include <unordered_map>

enum Direction
{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player 
{
    public:
        Player(int windowWidth, int windowHeight);
        Vector2 GetWorldPosition() { return worldPosition; }
        Vector2 GetScreenPosition();
        Rectangle GetCollisionRectangle();
        void Tick(float deltaTime);
        void UndoMoviment();
    private:
        Texture2D GetTextureForDirectionAndMovement(Direction direction, bool isMoving, Texture2D defaultTexture);
        Texture2D texture{LoadTexture("characters/Adam_idle_front_anim_16x16.png")};
        Texture2D idleFront{LoadTexture("characters/Adam_idle_front_anim_16x16.png")};
        Texture2D idleBack{LoadTexture("characters/Adam_idle_anim_back_16x16.png")};
        Texture2D idleLeft{LoadTexture("characters/Adam_idle_anim_left_16x16.png")};
        Texture2D idleRight{LoadTexture("characters/Adam_idle_anim_right_16x16.png")};
        Texture2D runFront{LoadTexture("characters/Adam_run_front_16x16.png")};
        Texture2D runBack{LoadTexture("characters/Adam_run_back_16x16.png")};
        Texture2D runRight{LoadTexture("characters/Adam_run_right_16x16.png")};
        Texture2D runLeft{LoadTexture("characters/Adam_run_left_16x16.png")};
        Vector2 worldPosition{};
        Vector2 worldPositionLastFrame{};
        Vector2 velocity{};
        Direction lastDirection{};
        float runningTime{};
        int frame{};
        int maxframes{6};
        float updateTime{1.f / 6.f};
        float speed{12.f};
        float width{};
        float height{};
        float scale{5.f};
        int windowWidth{};
        int windowHeight{};
};