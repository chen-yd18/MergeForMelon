#include "fruit_detect.h"
#include "fruit.h"

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b){
    // TODO
    double squareDistance = (a.centerX-b.centerX) * (a.centerX-b.centerX)
                          + (a.centerY-b.centerY) * (a.centerY-b.centerY);
    double squareRadiusSum = (fruitRadius[a.type] + fruitRadius[b.type])
                           * (fruitRadius[a.type] + fruitRadius[b.type]);
    return squareDistance <= squareRadiusSum;
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
    return a.centerX - fruitRadius[a.type] <= 0;
}

int isInRightWall(Fruit a){
    // TODO
    return a.centerX + fruitRadius[a.type] >= WINDOW_WIDTH;
}