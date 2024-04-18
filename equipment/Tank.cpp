#include "Tank.h"

Tank::Tank(std::string tankName, int initialWeight, AirLock& airLock) 
    : name(tankName), weight(initialWeight), airLockRef(airLock), pressure(0.0), state(TankState::Idle) {}

void Tank::fill(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    weight += amount;
    state = (state == TankState::Emptying) ? TankState::Transferring : TankState::Filling;
}

void Tank::empty(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    weight = std::max(0, weight - amount);
    state = (state == TankState::Filling) ? TankState::Transferring : TankState::Emptying;
}

void Tank::updateTank() {
    if (airLockRef.speedHz == 0) {
        // std::lock_guard<std::mutex> lock(mtx);
        state = TankState::Idle;
    }
}

void Tank::displayStatus() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << name << " Status: " << std::endl;
    std::cout << "Weight: " << weight << " pounds" << std::endl;
    std::cout << "State: " << static_cast<int>(state) << std::endl;  // Convert enum to int for simple display
}
