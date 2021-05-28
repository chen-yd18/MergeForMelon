#include "animation.h"
#include "window_const.h"
#include "fruit.h"

extern Texture2D goldenLight;
extern Texture2D bigWatermelon;

WatermelonAnimation generateWatermelonAnimation()
{
    return (WatermelonAnimation){totalFrames};
}

void drawWatermelonAnimation(WatermelonAnimation *anim)
{
    Vector2 lightPosition = (Vector2){WINDOW_WIDTH/2 - 2*fruitRadius[_WATERMELON], 
    WINDOW_HEIGHT*0.8*anim->remainingFrames/totalFrames - 2*fruitRadius[_WATERMELON]};
    Vector2 melonPosition = (Vector2){WINDOW_WIDTH/2 - fruitRadius[_WATERMELON], 
    WINDOW_HEIGHT*0.8*anim->remainingFrames/totalFrames - fruitRadius[_WATERMELON]};
    
    DrawTextureEx(goldenLight, lightPosition, 0, 2*fruitRadius[_WATERMELON]/goldenLightRadius, WHITE); 
    DrawTextureEx(bigWatermelon, melonPosition, 0, 1, WHITE);
    
	anim->remainingFrames--;
}

JuiceAnimation createJuiceAnimation(double X, double Y, int pretype, int totalFrames)
{
	double CenterX = X;
	double CenterY = Y;
	int type = pretype;
	int remainingFrames =  totalFrames;
    return (JuiceAnimation){CenterX, CenterY, type, remainingFrames};
}

extern Texture2D textureJuice[11];

void drawJuiceAnimation(JuiceAnimation *anim)
{   
    Vector2 position = (Vector2){anim->centerX-fruitRadius[anim->type],
                                 anim->centerY-fruitRadius[anim->type]};
    
    DrawTextureEx(textureJuice[anim->type], position, 0, 2.0*fruitRadius[anim->type]/juiceHeight, WHITE); 
    
	anim->remainingFrames--;
}