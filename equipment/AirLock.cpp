#include "AirLock.h"
#include <iostream>

AirLock::AirLock() : speedHz(0.0) {}

void AirLock::setSpeed(double hz) {
    speedHz = hz;
    std::cout << "AirLock speed set to " << speedHz << " Hz" << std::endl;
}