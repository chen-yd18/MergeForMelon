#include "fruit_merge.h"
#include "fruit_detect.h"
#include "fruit.h"
#include <stdio.h>

int mergeFruits(Fruit* fruits, int fruitCount, int* score)
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
            if((fruits[i].type==fruits[j].type
                ||(fruits[i].type==_TOMATO&&fruits[j].type==_CHERRY)
                ||(fruits[i].type==_CHERRY&&fruits[j].type==_TOMATO)
                ||(fruits[i].type==_PINEAPPLE&&fruits[j].type==_LEMON)
                ||(fruits[i].type==_LEMON&&fruits[j].type==_PINEAPPLE)) 
              && fruits[i].type < _WATERMELON
              && fruits[j].exists
              && isCollided(fruits[i], fruits[j]))
            {
                int type = fruits[i].type;
                if(fruits[j].type!=fruits[i].type) // same color
                {
                    if(fruits[i].type==_TOMATO || fruits[j].type==_TOMATO)
                    {
                        type = _TOMATO-1;
                    }
                    else
                    {
                        type = _PINEAPPLE-1;
                    }
                }
                double centerX = fruits[i].centerX;
                double centerY = fruits[i].centerY;
                // kill two old fruits by killFruit
                killFruit(&fruits[i]);
                killFruit(&fruits[j]);
                // create a new fruit
                Fruit sonFruit = generateFruit(type + 1, centerX, centerY);

                checkPos(&sonFruit);

                // add the new fruit to fruits
                fruits[fruitCount] = fruits[fruitCount-1];
                fruits[fruitCount-1] = sonFruit;
                fruitCount++; // fixed by cyd

                // change score
                *score += mergeScore[sonFruit.type];
                // printf("sonFruit.type: %d\n", sonFruit.type);
            }
        }
    }
    return fruitCount;
}