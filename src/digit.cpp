#include "digit.h"
#include "raylib.h"
#include <stdlib.h>

// draw digits on the screen.
void drawDigits(int score)
{
    static double scoreToDraw = 0.0;
    if (scoreToDraw<score)
        scoreToDraw += .4;
    // init for new game
    if (score==0 && scoreToDraw>0)
        scoreToDraw = 0;

    char scoreStr[10];
    itoa(int(scoreToDraw), scoreStr, 10);
    DrawText(scoreStr, 50, 50, 36, ORANGE);
}
