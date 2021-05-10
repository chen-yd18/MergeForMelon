#include "fruit.h"
#include "raylib.h"
#include <stdlib.h>

// 3 TODOs here

// creates a new unreleased fruit within the first 5 types.
struct Fruit newFruit()
{
    int type = rand()%MAX_SPAWN_TYPE + 1;
    return (struct Fruit){type, WINDOW_WIDTH/2, fruitRadius[type], 
            0.0, 0.0, 1, 0};
}

// set a fruit's 'exists' domain to 0 in order to kill it.
void killFruit(struct Fruit* fruit){
    // TODO: just kill it.
    
}

// generate a fruit with specified attributes.
struct Fruit generateFruit(int type, double centerX, double centerY)
{
    // TODO: generate a fruit
    // Note: be careful! which value should 'released' take?
    return (struct Fruit){100, 4.0, 4.0, 4.0, 4.0, 0, 0};
}

// draws a fruit on the window.
void drawFruit(struct Fruit fruit){
    // this is just a placeholder
    DrawCircle(fruit.centerX, fruit.centerY, fruitRadius[fruit.type], fruitColor[fruit.type]);
    // TODO: draw a REAL fruit on the screen!
    
}