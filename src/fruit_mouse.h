#ifndef FRUIT_MOUSE_H
#define FRUIT_MOUSE_H

// Move the floating fruit when the mouse moves.
// Drop the floating fruit when the mouse leftclicks.
// Function No.10

#include "raylib.h"
#include "fruit.h"

void handleMouseMove(Fruit* floating);

void handleMouseClick(Fruit* floating, Fruit* fruitArray, int fruitArrayLen);

#endif