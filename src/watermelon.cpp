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
#include "digit.h"
#include <stdio.h>

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
void addFruit(Fruit fruit)
{
    // TODO: add a fruit into the fruits array.
    //printf("%d %lf %lf %lf %lf %d %d\n", fruit.type, fruit.centerX,
    //fruit.centerY, fruit.veloX, fruit.veloY, fruit.exists, fruit.released);
    fruits[fruitCount++] = fruit;
}
void removeKilledFruit()
{
    // TODO: remove all fruits whose exists==0.
    
}
double accX[MAX_FRUIT_COUNT + 1], accY[MAX_FRUIT_COUNT + 1];

// music ON/OFF
int isMusicOn = 1;

// TODO: store animations here

// buttons
Image img;
struct Button startButton   = createButton(190, 250, 200, 80, img);
struct Button musicButton   = createButton(190, 250, 200, 80, img);
struct Button restartButton = createButton(190, 250, 200, 80, img);

// initialize the game
void initGame()
{
    // restore all states
    score = 0;
    HP = MAX_HP;
    memset(fruits, 0, sizeof(fruits));
    fruitCount = 0;
    // generate a new unreleased fruit
    addFruit(newFruit());
    // switch scene
    scene_id = 1;
}

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
            if(scene_id == 1 && HP > 0)
            {
                // TODO: change the releasedness of the unreleased fruit
                fruits[fruitCount-1].released = 1;
                // TODO: generate a new fruit which is unreleased
                addFruit(newFruit());
            }
            // press left button to trigger a button
            else
            {
                // check START button when scene_id==0
                if(scene_id == 0)
                {
                    if(inButton(startButton, mouseX, mouseY))
                    {
                        initGame();
                    }
                }
                // check RESTART button whene scene_id==1 and HP<=0
                else if(scene_id == 1)
                {
                    if(HP <= 0)
                    {
                        if(inButton(restartButton, mouseX, mouseY))
                        {
                            initGame();
                        }
                    }
                }
                // check MUSIC button when scene_id==2
                else if(scene_id == 2)
                {
                    if(inButton(musicButton, mouseX, mouseY))
                    {
                        // switch music ON/OFF
                        if(isMusicOn)
                        {
                            isMusicOn = 0;
                            // TODO: stop music
                        }
                        else
                        {
                            isMusicOn = 1;
                            // TODO: start music
                        }
                    }
                }
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
                HP -= 100; // TEST
            }
        }
        
        // TODO: simulate the motion of all fruits
        if(scene_id == 1)
        {
            if(HP <= 0)
            {
                // TODO: generate game over animations
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
            else if(HP>0) // the dead cannot be resurrected
            {
                HP = MAX_HP;
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
            DrawText("Merge for", 200, 90, 32, LIGHTGRAY);
            DrawText("MELON", 200, 140, 48, LIGHTGRAY);
            DrawText("PRESS BUTTON TO START", 180, 400, 16, LIGHTGRAY);
            DrawText("PRESS RIGHT KEY FOR SETTINGS", 160, 450, 16, LIGHTGRAY);
            
            //draw the START button
            drawButton(startButton);
            
            // TODO: play the music for START menu
        }
        else if(scene_id == 1)
        {
            // TODO: draw the background of the game scene
            // DrawRectangle(30, 70, 90, 50, GREEN);
            
            // draw the score of the game
            drawDigits(score);
            // draw all fruits
            // Note: this loop is reversed 
            //       in case that the newly generated fruit covers the falling fruit(s)
            for(int i=fruitCount-1;i>=0;i--)
            {
                drawFruit(fruits[i]);
            }
            // TODO: draw all animations
            
            // game over
            if(HP <= 0)
            {
                DrawText("GAME OVER", 200, 90, 32, RED);
                drawButton(restartButton);
                DrawText("RESTART", 220, 280, 24, LIGHTGRAY);
            }
            // TODO: play the music for the game scene
            
        }
        else if(scene_id == 2)
        {
            // TODO: draw the background of the SETTINGS scene
            DrawText("SETTINGS", 200, 90, 32, LIGHTGRAY);
            DrawText("Touch fish once refreshes your mood,", 150, 160, 16, LIGHTGRAY);
            DrawText("Touch fish twice brings you to DOOM.", 150, 200, 16, LIGHTGRAY);
            if(isMusicOn)
            {   
                DrawText("MUSIC: ON", 230, 400, 16, LIGHTGRAY);
            }
            else
            {
                DrawText("MUSIC: OFF", 230, 400, 16, LIGHTGRAY);
            }
            
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