#include "fruit.h"
#include <stdlib.h>
#include <time.h>

struct Fruit newFruit()
{
    srand(time(0));
    int level = rand()%MAX_SPAWN_LEVEL + 1;
    return (struct Fruit){level, WINDOW_WIDTH/2, fruitRadius[level], 
            0, 0, 1};
}