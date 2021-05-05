#ifndef FRUIT_MOVE_H
#define FRUIT_MOVE_H

// Provides a method to update the velocity of a fruit,
// and move the fruit according to the new velocity.
// Function No.12

#include "fruit.h"

// Step 1. modify the fruit's 'veloX' and 'veloY' domain 
// according to its accelerations in directions X&Y
// during a short period of time(t).
// Step 2. move the fruit according to its velocity in directions X&Y
// during a short period of time(t).
void fruitMove(Fruit* fruit, double accX, double accY, double t);

// calculate accX and accY for all fruits by Newton's laws.
void calculateAcc(Fruit* fruits, int fruitCount, double* accX, double* accY);

#endif