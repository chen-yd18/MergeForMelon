#include "button.h"

// Create a button.
struct Button createButton(int leftX, int topY, int width, int height, 
                  char* imageFileName)
{
    Image img;
    return (struct Button){leftX, topY, width, height, img};
}

// Draw a button on the window.
void drawButton(struct Button button)
{
    // TODO
    // this is just a placeholder
    DrawRectangle(button.leftX, button.topY, button.width, button.height, GREEN);
}

// Decides whether a mouse position (X,Y) is in the button.
int inButton(struct Button button, int mouseX, int mouseY)
{
    // TODO
    
    // Returns 1 when (X,Y) is in the button, 0 otherwise.
    return 0;
}