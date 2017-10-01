#include "RTC.h"

RTC::RTC()
{
  
}

void RTC::update()
{
  DateTime time = RTClib::now();

  data = ClockData(time.year(), time.month(), time.day(), time.hour(), time.minute(), time.second());
}

ClockData RTC::getData()
{
  return this->data;
}

