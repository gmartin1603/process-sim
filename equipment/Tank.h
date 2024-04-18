#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <mutex>
#include "AirLock.h"

enum class TankState { Idle, Filling, Emptying, Transferring };

class Tank {
public:
    std::string name;
    double pressure;
    int weight;
    TankState state;
    AirLock& airLockRef;
    std::mutex mtx;  // Mutex for thread-safe operations

    Tank(std::string tankName, int initialWeight, AirLock& airLock);
    void fill(int amount);
    void empty(int amount);
    void updateTank();
    void displayStatus();
};

#endif
