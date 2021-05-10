#ifndef FRUIT_DETECT_H
#define FRUIT_DETECT_H

// Provides methods to check whether two fruits collide,
// and whether a fruit runs over the dead line.
// Function No.11

#include "fruit.h"

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b);

// Calculates radius_a + radius_b - distance_ab.
double compressDepth(Fruit a, Fruit b);

// Decides whether the fruit goes over the dead line.
int isDead(Fruit a);

int isUnderGround(Fruit a);

int isInLeftWall(Fruit a);

int isInRightWall(Fruit a);

#endif
