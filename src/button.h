#ifndef BUTTON_H
#define BUTTON_H

// Defines the button struct.
// Utility for functions No.1 and 4

#include "raylib.h"

struct Button
{
    int leftX;
    int topY;
    int width;
    int height;
    Image image;
};

struct Button createButton(int leftX, int topY, int width, int height, 
                  char* imageFileName);

void drawButton(struct Button button);

int inButton(struct Button button, int mouseX, int mouseY);

#endif