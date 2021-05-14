#include "fruit_detect.h"
#include "fruit.h"
#include <math.h>

// Calculates radius_a + radius_b - distance_ab.
double compressDepth(Fruit a, Fruit b)
{
    double distance_ab = sqrt(
        (a.centerX - b.centerX)*(a.centerX - b.centerX)
      + (a.centerY - b.centerY)*(a.centerY - b.centerY));
    return double(fruitRadius[a.type] + fruitRadius[b.type]) - distance_ab;
}

// Decides whether the two fruits collide.
int isCollided(Fruit a, Fruit b)
{
    return compressDepth(a, b) >= 0;
}

// Decides whether the fruit goes over the dead line.
// except that if the fruit is unreleased.
int isDead(Fruit a)
{
    if (!a.released)
        return 0;
    return a.centerY-fruitRadius[a.type] <= DEADLINE_HEIGHT;
}

int isUnderGround(Fruit a)
{
    return a.centerY+fruitRadius[a.type] >= WINDOW_HEIGHT;
}

int isInLeftWall(Fruit a)
{
    return a.centerX-fruitRadius[a.type] <= 0;
}

int isInRightWall(Fruit a)
{
    return a.centerX+fruitRadius[a.type] >= WINDOW_WIDTH;
}
