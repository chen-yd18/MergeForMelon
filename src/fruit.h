#ifndef FRUIT_H
#define FRUIT_H

// Defines the fruit struct 
// as well as its constructor & renderer.
// Function No.9

#include "window_const.h"

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
    25, 45, 65, 70, 85,
    110, 110, 130, 155, 170,
    175
};

const int MAX_SPAWN_LEVEL = 5;

struct Fruit
{
    int type;
    int centerX;
    int centerY;
    int veloX;
    int veloY;
    int exists; // the fruit will be removed next frame if exists==0
};

struct Fruit newFruit();

#endif