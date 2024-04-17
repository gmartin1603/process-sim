#include <iostream>

class Blower {
public:
    double fullLoadAmps;
    double linePressure;

    Blower() : fullLoadAmps(2.0), linePressure(0.2) {}

    void updateBlower(double airLockSpeed) {
        fullLoadAmps = 2 + airLockSpeed * 2;  // Idle amps adjusted here
        linePressure = 0.2 + airLockSpeed * 1.5;  // Idle pressure adjusted here

        std::cout << "Blower full load amps: " << fullLoadAmps << std::endl;
        std::cout << "Blower line pressure: " << linePressure << std::endl;
    }
};