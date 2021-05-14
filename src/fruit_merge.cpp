#include "fruit_merge.h"
#include "fruit_detect.h"
#include "fruit.h"
#include <stdio.h>

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
                // kill two old fruits by killFruit
                killFruit(&fruits[i]);
                killFruit(&fruits[j]);
                // create a new fruit
                Fruit sonFruit = generateFruit(type + 1, centerX, centerY);
                fruits[fruitCount] = fruits[fruitCount-1];
                fruits[fruitCount-1] = sonFruit;
            }
        }
    }
    return fruitCount;
}