/*******************************************************************************************
*
*   Our first raylib project: Merge for Melon
*
*   This project has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   This is a course project for Fundamentals of Computer Programming, Spring 2021, Tsinghua Univ.
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
#include "resources.h"
#include "fruit_detect.h"
#include "fruit_move.h"
#include "button.h"

// It is a good habit to include standard header files
// after self-defined header files
// because it will be easier to find out
// the missing standard header files in self-defined header files
#include <string.h> // for memset

// global variables
// scene id
int scene_id = 0; // 0 for START, 1 for game, 2 for SETTINGS
int old_scene_id = 0; // the scene_id before entering SETTINGS menu

// game states
int score = 0; // game score
// HP: Decrements after each dead frame. 
//     Restores to MAX_HP after each alive frame.
//     Game overs when HP<=0.
const int MAX_HP = 60;
int HP = 60; 

// all about fruits
// NOTE: you should guarantee that 
//       only one unreleased fruit lies in the fruits array,
//       and it is the last element of the array.
Fruit fruits[MAX_FRUIT_COUNT + 1];
int fruitCount = 0;
void addFruit()
{
    // TODO: add a new unreleased fruit into the fruits array.
    
}
void removeKilledFruit()
{
    // TODO: remove all fruits whose exists==0.
    
}
double accX[MAX_FRUIT_COUNT + 1], accY[MAX_FRUIT_COUNT + 1];

// music ON/OFF
int isMusicOn = 1;

// buttons
struct Button startButton = createButton(30, 50, 100, 90, "TODO.png");
struct Button musicButton = createButton(50, 60, 80, 70, "TODO.png");

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Merge for Melon");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    // TODO: generate a new fruit which is unreleased
    
    //--------------------------------------------------------------------------------------

    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // this loop body will be executed each frame
        
        // Step 1. update everything before each frame
        // mouse status
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        bool isLeftButtonPressed = IsMouseButtonPressed(0);
        bool isRightButtonPressed = IsMouseButtonPressed(1);
        
        if(isLeftButtonPressed)
        {
            // press left button to release a fruit
            if(scene_id == 1)
            {
                // TODO: change the velocity of the unreleased fruit
            
                // TODO: generate a new fruit which is unreleased
                
            }
            // press left button to trigger a button
            else
            {
                // TODO: check START button when scene_id==0
                
                // TODO: check MUSIC button when scene_id==2
                
            }
        }
        
        // press right button to switch to and from SETTINGS menu
        if(isRightButtonPressed)
        {
            if(scene_id == 2)
            {
                scene_id = old_scene_id;
            }
            else
            {
                old_scene_id = scene_id;
                scene_id = 2;
            }
        }
        
        // TODO: simulate the motion of all fruits
        if(scene_id == 1)
        {
            if(HP <= 0)
            {
                // TODO: game over
            }
            // check dead and decrement HP
            int dead = 0;
            for(int i=0;i<fruitCount;i++)
            {
                if(isDead(fruits[i]))
                {
                    dead = 1;
                    break;
                }
            }
            if(dead)
            {
                HP--;
            }
            
            // simulate motions
            // get accelerations
            memset(accX, 0, sizeof(accX));
            memset(accY, 0, sizeof(accY));
            calculateAcc(fruits, fruitCount, accX, accY);
            // move fruits
            for(int i=0;i<fruitCount-1;i++) // excluding the unreleased fruit
            {
                fruitMove(fruits + i, accX[i], accY[i], FRAME_TIME);
            }    
        }
        // Step 2. draw everything in each frame
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if(scene_id == 0)
        {
            // TODO: draw the background for START menu
            // DrawRectangle(30, 70, 90, 50, RED);
            // DrawText("Congrats! You created the START menu!", 90, 200, 20, LIGHTGRAY);
            
            //draw the START button
            drawButton(startButton);
            
            // TODO: play the music for START menu
        }
        else if(scene_id == 1)
        {
            // TODO: draw the background of the game scene
            // DrawRectangle(30, 70, 90, 50, GREEN);
            
            // TODO: draw the score of the game
            
            // draw all fruits
            for(int i=0;i<fruitCount;i++)
            {
                drawFruit(fruits[i]);
            }
            // TODO: play the music for the game scene
            
        }
        else if(scene_id == 2)
        {
            // draw the MUSIC ON/OFF button
            drawButton(musicButton);
            
            // TODO: draw the FULLSCREEN/WINDOW button
            // NOTE: This function is very expensive but worths little.
            //       We'd better discard it.
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