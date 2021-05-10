#include "fruit_merge.h"
#include "fruit_detect.h"
#include "fruit.h"
#include <stdio.h>

// 2 TODOs

int mergeFruits(Fruit* fruits, int fruitCount)
{
    // There's no need to take cascading merges into account
    // because the duration of each frame is really short.
    for(int i=0; i<fruitCount-1; i++)
    {
        if(!fruits[i].exists)
        {
            continue;
        }
        for(int j=0; j<i; j++)
        {
            if(fruits[i].type==fruits[j].type
              && fruits[i].type < _WATERMELON
              && fruits[j].exists
              && isCollided(fruits[i], fruits[j]))
            {
                int type = fruits[i].type;
                double centerX = fruits[i].centerX;
                double centerY = fruits[i].centerY;
                // TODO: kill the two identical fruits
                // Note: recall what you've learnt about arrays&pointers.
                
                // TODO: add a fruit with attributes(type,centerX,centerY).
                // Note: the unreleased fruit must be the last one,
                //       so you should swap the last two fruits after adding.
                // Note: Be careful! When to increment fruitCount?
                
            }
        }
    }
    return fruitCount;
}