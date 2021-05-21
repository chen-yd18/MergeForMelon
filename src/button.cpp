#include "button.h"

// Create a button.
struct Button createButton(int leftX, int topY, int width, int height, 
                  Image image)
{
    return (struct Button){leftX, topY, width, height, image};
}

// Draw a button on the window.
void drawButton(struct Button button)
{
    // TODO
    // this is just a placeholder
    DrawRectangle(button.leftX, button.topY, button.width, button.height, BLANK);
}

// Decides whether a mouse position (X,Y) is in the button.
int inButton(struct Button button, int mouseX, int mouseY)
{
    // Returns 1 when (X,Y) is in the button, 0 otherwise.
    if(mouseX < button.leftX || mouseX > button.leftX + button.width)
    {
        return 0;
    }
    if(mouseY < button.topY || mouseY > button.topY + button.height)
    {
        return 0;
    }
    return 1;
}