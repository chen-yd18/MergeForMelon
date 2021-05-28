#include "fruit.h"
#include "fruit_detect.h"
#include "raylib.h"
#include <stdlib.h>

// creates a new unreleased fruit within the first 5 types.
Fruit newFruit()
{
    int type = rand()%MAX_SPAWN_TYPE + 1;
    return (Fruit){type, WINDOW_WIDTH/2, fruitRadius[type], 
            0, 0, 1, 0};
}

// set a fruit's 'exists' domain to 0 in order to kill it.
void killFruit(Fruit* fruit){
    fruit->exists = 0;
}

// generate a fruit with specified attributes.
Fruit generateFruit(int type, double centerX, double centerY)
{
    return (Fruit){type, centerX, centerY, 
            0, 0, 1, 1};
}

// draws a fruit on the window.
void drawFruit(Fruit fruit,Texture2D* texture)
{
    double X = fruit.centerX - fruitRadius[fruit.type];
    double Y = fruit.centerY - fruitRadius[fruit.type];
   	if (fruit.type == _GRAPE)
    {
        DrawTexture(texture[1], X, Y, WHITE);
    }
    else if (fruit.type == _CHERRY)
    {
        DrawTexture(texture[2], X, Y, WHITE);
    } 
	else if (fruit.type == _ORANGE)    
	{
        DrawTexture(texture[3], X, Y, WHITE);
    } 
	else if (fruit.type == _LEMON)
    {
       DrawTexture(texture[4], X, Y, WHITE);
    }
	else if (fruit.type == _KIWIFRUIT)
    {
        DrawTexture(texture[5], X, Y, WHITE);
    } 
    else if (fruit.type == _TOMATO)
    {
       DrawTexture(texture[6], X, Y, WHITE);
    } 
	else if (fruit.type == _PEACH)
    {
       DrawTexture(texture[7], X, Y, WHITE);
    } 
	else if (fruit.type == _PINEAPPLE)
    {
        DrawTexture(texture[8], X, Y, WHITE);
    }  
	else if (fruit.type == _COCONUT)
    {
        DrawTexture(texture[9], X, Y, WHITE);
    } 
	else if (fruit.type == _HALFMELON)
    {
        DrawTexture(texture[10], X, Y, WHITE);
    }  
    else if (fruit.type == _WATERMELON)
    {
       DrawTexture(texture[11], X, Y, WHITE);
    } 
}

void checkPos(Fruit* fruit)
{
    if (isInLeftWall(*fruit))
    {
        fruit->centerX = fruitRadius[fruit->type];
    }
    if (isInRightWall(*fruit))
    {
        fruit->centerX = WINDOW_WIDTH - fruitRadius[fruit->type];
    }
    if (isUnderGround(*fruit))
    {
        fruit->centerY = WINDOW_HEIGHT - fruitRadius[fruit->type];
    }
}
