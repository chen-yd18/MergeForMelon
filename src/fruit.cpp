#include "fruit.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

// creates a new unreleased fruit within the lowest 5 levels.
struct Fruit newFruit()
{
    srand(time(0));
    int level = rand()%MAX_SPAWN_LEVEL + 1;
    return (struct Fruit){level, WINDOW_WIDTH/2, fruitRadius[level], 
            0, 0, 1, 0};
}

// set a fruit's 'exists' domain to 0 in order to kill it.
void killFruit(struct Fruit* fruit){
    // TODO
}

// draws a fruit on the window.
void drawFruit(struct Fruit fruit){
    DrawCircle(fruit.centerX, fruit.centerY, fruitRadius[fruit.type], fruitColor[fruit.type]);
}