#include <thread>
#include <chrono>
#include <conio.h>  // For _kbhit() and _getch()
#include <mutex>
#include "equipment/AirLock.h"
#include "equipment/Blower.h"

std::mutex mtx; // Mutex for thread-safe output

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
