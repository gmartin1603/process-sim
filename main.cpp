#include <thread>
#include <chrono>
#include <conio.h> // For _kbhit() and _getch()
#include <mutex>
#include "equipment/AirLock.h"
#include "equipment/Blower.h"
#include "equipment/Tank.h"

// Simulation control variables
std::chrono::milliseconds baseInterval(500); // Base update interval of 500 ms
double speedMultiplier = 1.0; // Speed multiplier, adjust this for different scenarios
std::mutex mtx; // Mutex for thread safety

//TODO: Implement setSimulationSpeed function to UI control
void setSimulationSpeed(double multiplier) {
    std::lock_guard<std::mutex> lock(mtx);
    speedMultiplier = multiplier;
}

void runDisplay(Blower *blower, Tank *tank, Tank *lineOne)
{
  while (true)
  {
    blower->displayStatus();
    tank->displayStatus();
    lineOne->displayStatus();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main()
{
  AirLock myAirLock;
  Blower myBlower(myAirLock);
  Tank myTank("Tank 1", 10000000, myAirLock);
  Tank lineOne("Line 1 Wenger", 0, myAirLock);

  std::thread displayThread(runDisplay, &myBlower, &myTank, &lineOne);

  while (true)
  {
    if (_kbhit())
    {
      char ch = _getch();
      if (ch == 'q')
        break;
      mtx.lock();
      if (ch == 'w')
      {
        myAirLock.speedHz += 1;
      }
      if (ch == 's')
      {
        myAirLock.speedHz -= 1;
        myAirLock.speedHz = std::max(0.0, myAirLock.speedHz); // Ensure speed doesn't go negative
      }

      // if (myAirLock.speedHz > 0)
      // {
      //   myTank.empty(static_cast<int>(myAirLock.speedHz * 10));
      //   lineOne.fill(static_cast<int>(myAirLock.speedHz * 10));
      // }

      myBlower.updateBlower();
      mtx.unlock();
    }

    if (myAirLock.speedHz > 0)
    {
      myTank.empty(static_cast<int>(myAirLock.speedHz * 10));
      lineOne.fill(static_cast<int>(myAirLock.speedHz * 10));
    }

    myTank.updateTank();
    lineOne.updateTank();

    std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(baseInterval / speedMultiplier));
  }

  displayThread.detach(); // Detach the thread
  return 0;
}
