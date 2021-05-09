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
    for(int i=0; i<fruitCount; i++)
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
        for(int j=0; j<fruitCount; j++)
        {
            if(i!=j && fruits[j].released 
                && fruits[i].centerY < fruits[j].centerY 
                && isCollided(fruits[i], fruits[j]))
            {
                supportCount[i]++;
                supportIndex[i] = j;
            }
        }
    }
    for(int i=0; i<fruitCount; i++)
    {
        //printf("%d %d\n",i, supportCount[i]);
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
                int j = supportIndex[i];
                // be careful on the sign of each subtraction
                double tanTheta = (fruits[i].centerX-fruits[j].centerX) 
                    / (fruits[j].centerY-fruits[i].centerY);
                double theta = atan(tanTheta);
                accX[i] = GRAVITY * sin(theta) * cos(theta);
                accY[i] = GRAVITY * sin(theta) * sin(theta);
                // change velocity
                double old_vx = fruits[i].veloX;
                double old_vy = fruits[i].veloY;
                double new_vx = 0.0;
                double new_vy = 0.0;
                if(old_vx * (fruits[j].centerX-fruits[i].centerX) > 0.0)
                {
                    double v = old_vx * sin(-theta);
                    new_vx += v * sin(-theta);
                    new_vy -= v * cos(-theta);
                }
                else
                {
                    new_vx += old_vx;
                }
                if(old_vy > 0.0)
                {
                    double v = old_vy * sin(theta);
                    new_vx += v * cos(theta);
                    new_vy += v * sin(theta);
                }
                else
                {
                    new_vy += old_vy;
                }
                fruits[i].veloX = new_vx;
                fruits[i].veloY = new_vy;
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