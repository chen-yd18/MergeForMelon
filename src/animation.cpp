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

void drawJuiceAnimation(JuiceAnimation *anim)
{
	Texture2D texture; 
	
	if(anim->type == 1)
	{
		Image background = LoadImage("picture/juice/grapeJuice.png"); //purple
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 2)
	{
		Image background = LoadImage("picture/juice/cherryJuice.png"); //red
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 3)
	{
		Image background = LoadImage("picture/juice/orangeJuice.png"); //orange
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 4)
	{
		Image background = LoadImage("picture/juice/lemonJuice.png"); //yellow
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 5)
	{
		Image background = LoadImage("picture/juice/kiwifruitJuice.png"); //green
        texture = LoadTextureFromImage(background);
	}
	
    else if(anim->type == 6)
	{
		Image background = LoadImage("picture/juice/tomatoJuice.png"); //red
        texture = LoadTextureFromImage(background);
	}
    
	else if(anim->type == 7)
	{
		Image background = LoadImage("picture/juice/peachJuice.png"); //yellow
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 8)
	{
		Image background = LoadImage("picture/juice/pineappleJuice.png"); //yellow
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 9)
	{
		Image background = LoadImage("picture/juice/coconutJuice.png"); //white
        texture = LoadTextureFromImage(background);
	}
	
	else if(anim->type == 10)
	{
		Image background = LoadImage("picture/juice/halfmelonJuice.png"); //red
        texture = LoadTextureFromImage(background);
	}
    
    Vector2 position = (Vector2){anim->centerX-fruitRadius[anim->type],
                                 anim->centerY-fruitRadius[anim->type]};
    
    DrawTextureEx(texture, position, 0, 2.0*fruitRadius[anim->type]/juiceHeight, WHITE); 
    
	anim->remainingFrames--;
}