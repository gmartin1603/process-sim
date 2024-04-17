#include "Blower.h"
#include <iostream>
#include <mutex>
#include <cstdlib> // For system("cls")

extern std::mutex mtx; // Use the mutex declared in main.cpp

Blower::Blower(AirLock& airLock) : airLockRef(airLock), fullLoadAmps(2.0), linePressure(0.2) {}

void Blower::updateBlower() {
    fullLoadAmps = 2 + airLockRef.speedHz * 2;
    linePressure = 0.2 + airLockRef.speedHz * 1.5;
}

void Blower::displayStatus() {
    mtx.lock();
    system("cls");
    std::cout << "AirLock Speed: " << airLockRef.speedHz << " Hz" << std::endl;
    std::cout << "Blower Full Load Amps: " << fullLoadAmps << std::endl;
    std::cout << "Blower Line Pressure: " << linePressure << std::endl;
    mtx.unlock();
}
