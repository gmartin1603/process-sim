#ifndef BLOWER_H
#define BLOWER_H

#include "AirLock.h"

class Blower {
public:
    double fullLoadAmps;
    double linePressure;
    AirLock& airLockRef;

    Blower(AirLock& airLock);
    void updateBlower();
    void displayStatus();
};

#endif
