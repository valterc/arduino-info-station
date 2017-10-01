#ifndef InfoStation_h
#define InfoStation_h

#include "Display.h"
#include "Wifi.h"
#include "Sensors.h"

#include "RTC.h"

class InfoStation
{
  private:
    Display display;
    Wifi wifi;
    Sensors sensors;
    
  public:
    InfoStation();
    void run();

};

#endif
