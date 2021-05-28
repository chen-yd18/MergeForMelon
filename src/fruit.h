#ifndef FRUIT_H
#define FRUIT_H

// Defines the fruit struct 
// as well as its constructor & renderer.
// Function No.9

#include "window_const.h"
#include "raylib.h"

enum fruitType
{
    _NOFRUIT, 
    _GRAPE, _CHERRY, _ORANGE, _LEMON, _KIWIFRUIT,
    _TOMATO, _PEACH, _PINEAPPLE, _COCONUT, _HALFMELON,
    _WATERMELON
};

const int fruitRadius[12] = 
{
    0,
    26, 40, 54, 59, 76,
    91, 96, 129, 154, 154,
    204
};

const int goldenLightRadius = 128;
const int juiceWidth = 319;
const int juiceHeight = 292;

// This is deprecated.
const Color fruitColor[12] =
{
    RAYWHITE,
    PURPLE, MAROON, ORANGE, YELLOW, LIME,
    RED, PINK, GOLD, SKYBLUE, GREEN,
    DARKGREEN
};

// the score for each merged fruit
const int mergeScore[12] = 
{
    0, // _NOFRUIT
    0,  // grape
    2, 3, 4, 5, 6, 7, 8, 9, 10,
    100 // full watermelon
};

const int fruitScoreAtGameOver[12] = 
{
    0,  // _NOFRUIT
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

const int MAX_SPAWN_TYPE = 5;

struct Fruit
{
    int type;
    double centerX;
    double centerY;
    double veloX;
    double veloY;
    int exists; // the fruit will be removed next frame if exists==0
    int released; // gravity will not work on the fruit if released==0
};

// creates a new unreleased fruit within the lowest 5 levels.
Fruit newFruit();

// set a fruit's 'exists' domain to 0 in order to kill it.
void killFruit(Fruit* fruit);

// generate a fruit with specified attributes.
Fruit generateFruit(int type, double centerX, double centerY);

// draws a fruit on the window.
void drawFruit(Fruit fruit, Texture2D *texture);

// make sure the fruit is not in any wall or ground:
// check if the new fruit will be stucked in wall/ground,
// if so, change centerX/centerY to avoid this 
void checkPos(Fruit* fruit);

#endif