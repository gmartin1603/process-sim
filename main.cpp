#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>  // For _kbhit() and _getch()
#include <mutex>

std::mutex mtx; // Mutex for thread-safe output

class AirLock {
public:
    double speedHz;
    AirLock() : speedHz(0.0) {}
};

class Blower {
public:
    double fullLoadAmps;
    double linePressure;
    AirLock& airLockRef; // Reference to an AirLock object

    Blower(AirLock& airLock) : airLockRef(airLock), fullLoadAmps(2.0), linePressure(0.2) {}

    void updateBlower() {
        fullLoadAmps = 2 + airLockRef.speedHz * 2;
        linePressure = 0.2 + airLockRef.speedHz * 1.5;
    }

    void displayStatus() {
        mtx.lock();
        system("cls");
        std::cout << "AirLock Speed: " << airLockRef.speedHz << " Hz" << std::endl;
        std::cout << "Blower Full Load Amps: " << fullLoadAmps << std::endl;
        std::cout << "Blower Line Pressure: " << linePressure << std::endl;
        mtx.unlock();
    }
};

void runDisplay(Blower* blower) {
    while (true) {
        blower->displayStatus();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    AirLock myAirLock;
    Blower myBlower(myAirLock);
    std::thread displayThread(runDisplay, &myBlower);

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q') break;
            mtx.lock();
            if (ch == 'w') {
                myAirLock.speedHz += 5;
            }
            if (ch == 's') {
                myAirLock.speedHz -= 5;
                myAirLock.speedHz = std::max(0.0, myAirLock.speedHz); // Ensure speed doesn't go negative
            }
            myBlower.updateBlower();
            mtx.unlock();
        }
    }

    displayThread.detach(); // Detach the thread
    return 0;
}
