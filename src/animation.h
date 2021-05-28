#ifndef ANIMATION_H
#define ANIMATION_H

// Renders the WATERMELON animation
// and GAMEOVER animation.
// Function No.7

#include "raylib.h"

const int totalFrames = 100;

typedef struct 
{
	int remainingFrames;
}WatermelonAnimation;

WatermelonAnimation generateWatermelonAnimation();

void drawWatermelonAnimation(WatermelonAnimation *anim);

typedef struct 
{
	double centerX;
	double centerY;
	int type;
	int remainingFrames;
}JuiceAnimation;

JuiceAnimation createJuiceAnimation(double X, double Y, int pretype, int totalFrames);

void drawJuiceAnimation(JuiceAnimation *anim);



#endif