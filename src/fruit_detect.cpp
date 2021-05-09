#include "fruit_detect.h"
#include "fruit.h"

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b){
    // TODO
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