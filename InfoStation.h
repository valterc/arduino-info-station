#ifndef InfoStation_h
#define InfoStation_h

#include "Logger.h"
#include "Display.h"
#include "Wifi.h"
#include "Sensors.h"
#include "TemperatureHistory.h"

#include "RTC.h"

class InfoStation
{
  private:
    Display display;
    Wifi wifi;
    Sensors sensors;
	RTC rtc;
	TemperatureHistory history;
	
  public:
    InfoStation();
    void run();

};

#endif
