#include "fruit.h"
#include "raylib.h"
#include <stdlib.h>

// creates a new unreleased fruit within the first 5 types.
struct Fruit newFruit()
{
    int type = rand()%MAX_SPAWN_TYPE + 1;
    return (struct Fruit){type, WINDOW_WIDTH/2, fruitRadius[type], 
            0, 0, 1, 0};
}

// set a fruit's 'exists' domain to 0 in order to kill it.
void killFruit(struct Fruit* fruit){
    // TODO
    fruit->exists = 0;
}

// generate a fruit with specified attributes.
struct Fruit generateFruit(int type, double centerX, double centerY)
{
    return (struct Fruit){type, centerX, centerY, 
            0, 0, 1, 1};
}

// draws a fruit on the window.
void drawFruit(struct Fruit fruit){
    DrawCircle(fruit.centerX, fruit.centerY, fruitRadius[fruit.type], fruitColor[fruit.type]);
}