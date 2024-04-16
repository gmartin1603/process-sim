#include <iostream>

class AirLock {
public:
    double speedHz;  // Speed in hertz

    AirLock() : speedHz(0.0) {}

    void setSpeed(double hz) {
        speedHz = hz;
        std::cout << "AirLock speed set to " << speedHz << " Hz" << std::endl;
    }
};

class Blower {
public:
    double fullLoadAmps;  // Full load amperage of the blower
    double linePressure;  // Line pressure in the blower system

    Blower() : fullLoadAmps(0.0), linePressure(0.0) {}

    void updateBlower(double airLockSpeed) {
        fullLoadAmps = 10 + airLockSpeed * 2;  // Example relationship
        linePressure = 5 + airLockSpeed * 1.5;  // Example relationship

        std::cout << "Blower full load amps: " << fullLoadAmps << std::endl;
        std::cout << "Blower line pressure: " << linePressure << std::endl;
    }
};


int main() {
    AirLock myAirLock;
    Blower myBlower;

    double speed;
    std::cout << "Enter airlock speed in Hz: ";
    std::cin >> speed;

    myAirLock.setSpeed(speed);
    myBlower.updateBlower(myAirLock.speedHz);

    return 0;
}
