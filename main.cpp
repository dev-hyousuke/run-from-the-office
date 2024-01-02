#include "raylib.h"
#include "raymath.h"
#include "GameManager.h"
#include "Timer.h"
#include "Map.h"
#include "Wall.h"
#include "Player.h"
#include "UIManager.h"
#include "Button.h"

int main()
{
    GameManager gameManager;
    UIManager uiManager;
    Timer timer{15};
    Map map;
    Player player{gameManager.GetWindowWidth(), gameManager.GetWindowHeight()};
    Button button{ Vector2{3640, 1700}, 50, 50 };
    
    Wall wall1{ Vector2{120, 170}, 9, 1380 };
    Wall wall2{ Vector2{900, 170}, 9, 1000 };
    Wall wall3{ Vector2{1015, 170}, 9, 850 };
    Wall wall4{ Vector2{2300, 170}, 9, 850 };
    Wall wall5{ Vector2{2808, 1540}, 9, 800 };
    Wall wall6{ Vector2{3070, 1540}, 9, 280 };
    Wall wall7{ Vector2{3718, 1050}, 9, 1300 };
    Wall wall8{ Vector2{120, 1540}, 2690, 9 };
    Wall wall9{ Vector2{900, 1160}, 650, 9 };
    Wall wall10{ Vector2{1800, 1160}, 1900, 9 };
    Wall wall11{ Vector2{3070, 1540}, 650, 9 };
    Wall wall12{ Vector2{3070, 1820}, 250, 9 };
    Wall wall13{ Vector2{2808, 2300}, 900, 9 };
    Wall wall14{ Vector2{900, 1020}, 650, 9 };
    Wall wall15{ Vector2{1800, 1020}, 500, 9 };
    Wall wall16{ Vector2{120, 270}, 2200, 9 };
    Wall wall17{ Vector2{1550, 1020}, 9, 50 };
    Wall wall18{ Vector2{1800, 1020}, 9, 50 };
    Wall wall19{ Vector2{3200, 1650}, 500, 9 };

    Wall walls[] { wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, wall9, wall10, wall11, wall12, wall13, wall14, wall15, wall16, wall17, wall18, wall19 };

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        map.DrawMap(player.GetWorldPosition(), gameManager.GetWindowWidth(), gameManager.GetWindowHeight());
    
        player.Tick(GetFrameTime());

        for (auto wall : walls)
            if(CheckCollisionRecs(wall.GetCollisonRectangle(player.GetWorldPosition()), player.GetCollisionRectangle()))
                player.UndoMoviment();

        if (CheckCollisionRecs(button.GetCollisonRectangle(player.GetWorldPosition()), player.GetCollisionRectangle()) && IsKeyPressed(KEY_E) && timer.GetRemainingTime() > 0 )
            button.SetWasPressed();
    
        if (timer.GetRemainingTime() <= 0 && !button.GetWasPressed())
        {
            uiManager.DrawGameOver(gameManager.GetWindowWidth(), gameManager.GetWindowHeight());
            timer.DisableTimer();
        }
        else if(button.GetWasPressed())
        {
            uiManager.DrawWinGame(gameManager.GetWindowWidth(), gameManager.GetWindowHeight());        
            timer.DisableTimer();
        }
        else uiManager.DrawTimer(timer.GetRemainingTime());

        EndDrawing();
    }
 
    CloseWindow();
}