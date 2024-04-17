#ifndef TANK_H
#define TANK_H

#include <iostream>
#include "AirLock.h"  // Include AirLock instead of Blower

class Tank {
public:
    std::string name;  // Name of the tank e.g., "Tank 1"
    double pressure;   // Pressure in the tank
    int weight;        // Weight of the tank content in pounds, e.g., 10000
    AirLock& airLockRef;  // Reference to AirLock

    Tank(std::string tankName, int initialWeight, AirLock& airLock); 
    void updateTank();
    void displayStatus();
};

#endif
