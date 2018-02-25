#ifndef ForecastData_h
#define ForecastData_h

#include <Arduino.h>
#include "WeatherData.h"

class ForecastData : WeatherData
{
  private:
    

  public:

	String date;
  
    ForecastData();

};

#endif