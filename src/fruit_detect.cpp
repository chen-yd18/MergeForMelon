#include "fruit_detect.h"
#include "fruit.h"
#include <math.h>

// 5 TODOs here

// Calculates radius_a + radius_b - distance_ab.
double compressDepth(Fruit a, Fruit b)
{
    // TODO: calculate the depth step by step
    // Step 1. calculate the sum of each fruit's radius
    
    // Step 2. calculate the Euclidian distance between each fruit's center
    
    // Step 3. subtract them and return
    return 4.0;
}

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b){
    // TODO: decide collision with the help of compressDepth.
    return 0;
}

// Decides whether the fruit goes over the dead line.
int isDead(Fruit a){
    // TODO: compare the fruit's centerY with DEADLINE_HEIGHT.
    // Note: the smaller Y-value, the higher position.
    // Note: when a fruit hits the deadline, the game can be restarted;
    //       when you misses the deadline, the project will get messed.
    
    return 0;
}

int isUnderGround(Fruit a){
    return a.centerY + fruitRadius[a.type] >= WINDOW_HEIGHT;
}

int isInLeftWall(Fruit a){
    // TODO: decide it following the function isUnderGround
    return 0;
}

int isInRightWall(Fruit a){
    // TODO: decide it following the function isUnderGround
    return 0;
}