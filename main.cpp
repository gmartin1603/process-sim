#include <thread>
#include <chrono>
#include <conio.h> // For _kbhit() and _getch()
#include <mutex>
#include "equipment/AirLock.h"
#include "equipment/Blower.h"
#include "equipment/Tank.h"

std::mutex mtx; // Mutex for thread-safe output

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
      myTank.empty(static_cast<int>(myAirLock.speedHz));
      lineOne.fill(static_cast<int>(myAirLock.speedHz));
    }

    myTank.updateTank();
    lineOne.updateTank();
  }

  displayThread.detach(); // Detach the thread
  return 0;
}
