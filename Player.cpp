#include "Player.h"
#include "raymath.h"

Player::Player(int windowWidth, int windowHeight) :
    windowWidth(windowWidth),
    windowHeight(windowHeight)
{
    width = texture.width / maxframes;
    height = texture.height;
}

Vector2 Player::GetScreenPosition()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)
    };
}

Rectangle Player::GetCollisionRectangle()
{
    return Rectangle{
        GetScreenPosition().x,
        GetScreenPosition().y,
        width * scale,
        height * scale
    };
}

void Player::Tick(float deltaTime)
{
    if (IsKeyDown(KEY_A))
    {
        velocity.x -= 1.0; 
        lastDirection = LEFT; 
    } 
    if (IsKeyDown(KEY_D))
    {
        velocity.x += 1.0; 
        lastDirection = RIGHT; 
    } 
    if (IsKeyDown(KEY_W))
    {
        velocity.y -= 1.0; 
        lastDirection = UP; 
    } 
    if (IsKeyDown(KEY_S))
    {
        velocity.y += 1.0; 
        lastDirection = DOWN; 
    } 

    worldPositionLastFrame = worldPosition;

    runningTime += deltaTime;
    if (runningTime > updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxframes) frame = 0;
    }

    Rectangle source{
        frame * width,
        0.f,
        width,
        height
    };

    Rectangle dest{
        GetScreenPosition().x,
        GetScreenPosition().y,
        scale * width,
        scale * height
    };
    
    worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), speed));
    
    texture = GetTextureForDirectionAndMovement(lastDirection, Vector2Length(velocity) != 0.0, texture);

    velocity = {};
    
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Player::UndoMoviment()
{
    worldPosition = worldPositionLastFrame;
}

Texture2D Player::GetTextureForDirectionAndMovement(Direction direction, bool isMoving, Texture2D defaultTexture) {
    const std::unordered_map<Direction, Texture2D> textureMap = {
        {UP, isMoving ? runBack : idleBack},
        {DOWN, isMoving ? runFront : idleFront},
        {RIGHT, isMoving ? runRight : idleRight},
        {LEFT, isMoving ? runLeft : idleLeft}
    };

    auto it = textureMap.find(direction);
    return (it != textureMap.end()) ? it->second : defaultTexture;
}