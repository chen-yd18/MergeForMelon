#include "fruit_detect.h"
#include "fruit.h"
#include <math.h>

// Calculates radius_a + radius_b - distance_ab.
double compressDepth(Fruit a, Fruit b)
{
    // TODO
    return 4.0;
}

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b){
    
    // TODO
    // Note: ask compressDepth for help.
    return 0;
}

// Decides whether the fruit goes over the dead line.
int isDead(Fruit a){
    // TODO
    return 0;
}

int isUnderGround(Fruit a){
    return a.centerY + fruitRadius[a.type] >= WINDOW_HEIGHT;
}

int isInLeftWall(Fruit a){
    // TODO
    return 0;
}

int isInRightWall(Fruit a){
    // TODO
    return 0;
}