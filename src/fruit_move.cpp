#include "fruit_move.h"
#include "window_const.h"
#include "fruit_detect.h"
#include <math.h>
#include <stdio.h>

// Step 1. modify the fruit's 'veloX' and 'veloY' domain 
// according to its accelerations in directions X&Y
// during a short period of time(t).
// Step 2. move the fruit according to its velocity in directions X&Y
// during a short period of time(t).
void fruitMove(Fruit* fruit, double accX, double accY, double t){
    // Step 1
    fruit->veloX += accX * t;
    fruit->veloY += accY * t;
    // Step 2
    fruit->centerX += fruit->veloX * t;
    fruit->centerY += fruit->veloY * t;
}

const int GROUND = -1;
const int LEFT_WALL = -2;
const int RIGHT_WALL = -3;
// calculate accX and accY for all fruits by Newton's laws.
void calculateAcc(Fruit* fruits, int fruitCount, double* accX, double* accY){
    // Counts the number of fruits that collides with and lies below each fruit.
    int supportCount[MAX_FRUIT_COUNT + 1] = {0};
    // Records the index of ONE OF the fruits that collides with and lies below each fruit.
    int supportIndex[MAX_FRUIT_COUNT + 1] = {0};
    int i, j;
    for(i=0; i<fruitCount; i++)
    {
        if(!fruits[i].released)
        {
            continue;
        }
        // check whether the fruit is under ground
        if(isUnderGround(fruits[i]))
        {
            supportCount[i]++;
            supportIndex[i] = GROUND;
        }
        // TODO: check whether the fruit is in walls(left&right)
        
        // check whether the fruit collides with and lies above each fruit.
        for(j=0; j<fruitCount; j++)
        {
            if(i!=j && fruits[j].released 
                && fruits[i].centerY > fruits[i].centerY 
                && isCollided(fruits[i], fruits[j]))
            {
                supportCount[i]++;
                supportIndex[i] = j;
            }
        }
    }
    for(int i=0; i<fruitCount; i++)
    {
        // We do not move fruits with at least 2 supports.
        // It might bring inefficiency, but it is pretty easy.
        if(supportCount[i] >= 2)
        {
            // We put 0.0 instead of 0 here because 0.0 looks cute.
            accX[i] = 0.0;
            accY[i] = 0.0;
            fruits[i].veloX = 0.0;
            fruits[i].veloY = 0.0;
        }
        // If only one support is present, 
        // work out the accelerations by Newton's law.
        else if(supportCount[i] == 1)
        {
            if(supportIndex[i] == GROUND)
            {
                accX[i] = 0.0;
                accY[i] = 0.0;
                fruits[i].veloX = 0.0;
                fruits[i].veloY = 0.0;
            }
            else if(supportIndex[i] == LEFT_WALL)
            {
                // TODO
            }
            else if(supportIndex[i] == RIGHT_WALL)
            {
                // TODO
            }
            else
            {
                // be careful on the sign of each subtraction
                double tanTheta = (fruits[i].centerX-fruits[j].centerX) 
                    / (fruits[j].centerX-fruits[j].centerY);
                double theta = atan(tanTheta);
                accX[i] = GRAVITY * cos(theta) * cos(theta);
                accY[i] = GRAVITY * cos(theta) * sin(theta);
            }
        }
        // If a fruit has no support,
        // it falls freely.
        else if(supportCount[i] == 0)
        {
            accX[i] = 0.0;
            accY[i] = GRAVITY;
        }
    }
}