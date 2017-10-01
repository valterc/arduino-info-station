#ifndef RTC_h
#define RTC_h

#include <Wire.h>
#include "src/DS3231.h"

#include "ClockData.h"

class RTC
{
  private:
    ClockData data;
    
  public:
    RTC();
    void update();
    ClockData getData();
};

#endif
