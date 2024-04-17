#include "Tank.h"

Tank::Tank(std::string tankName, int initialWeight, AirLock& airLock) 
    : name(tankName), weight(initialWeight), airLockRef(airLock), pressure(0.0) {}

void Tank::updateTank() {
    if (airLockRef.speedHz > 0) {
        int weightLoss = static_cast<int>(airLockRef.speedHz * 10);  // Basic calculation, adjust as necessary
        weight = std::max(0, weight - weightLoss);  // Ensure weight doesn't go negative
    }
}

void Tank::displayStatus() {
    std::cout << name << " Status: " << std::endl;
    std::cout << "Weight: " << weight << " pounds" << std::endl;
    std::cout << "Tank Pressure: " << pressure << " psi" << std::endl;
}
