/*******************************************************************************************
*
*   Our first raylib project: Merge for Melon
*
*   This project has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   This is a course project for Foundations of Computer Programming, Spring 2021, Tsinghua Univ.
*   Professor: Liu Yang, Dept. of Computer Science
*   TA       : Chen Chi, Dept. of Computer Science
*   Students : Chen Yande, School of Software
*              Duan Yiran, Dept. of Environmental Engineering
*              Yang Jianfan, School of Life Science
*              Yang Zuyi, School of Life Science
*              Chen Yiliang, School of Life Science
*
********************************************************************************************/

#include "raylib.h"
#include "window_const.h"
#include "fruit.h"

// Global variables
// TODO: Put game states here
int scene_id = 0;
Image wabbit = LoadImage("wabbit_alpha.png");
Texture2D wabbit_texture = LoadTextureFromImage(wabbit);
Fruit nf = newFruit();

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Merge for Melon");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        
        if(IsMouseButtonPressed(0) && mouseX>=30 && mouseX <= 120 && mouseY >= 70 && mouseY <= 120) // 0-left 1-right
        {
            scene_id = (scene_id + 1) % 3;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(wabbit_texture, 120, 250, WHITE);
        DrawTexture(wabbit_texture, 142, 256, WHITE);
        if(scene_id == 0)
        {
            DrawRectangle(30, 70, 90, 50, RED);
        }
        else if(scene_id == 1)
        {
            DrawRectangle(30, 70, 90, 50, GREEN);
        }
        else if(scene_id == 2)
        {
            DrawRectangle(30, 70, 90, 50, YELLOW);
        }
        if(scene_id == 0)
        {
            DrawText("Congrats! You created the START menu!", 90, 200, 20, LIGHTGRAY);
        }
        else if(scene_id == 1)
        {
            DrawText("Congrats! You created the main game!", 90, 200, 20, LIGHTGRAY);
        }
        else if(scene_id == 2)
        {
            DrawText("Congrats! You created the SETTINGS menu!", 90, 200, 20, LIGHTGRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}