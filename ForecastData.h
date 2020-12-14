#ifndef ForecastData_h
#define ForecastData_h

#include <Arduino.h>
#include "WeatherData.h"

class ForecastData : WeatherData
{
  private:
    String date;

  public:
    ForecastData();
	
	String& getDateString();
	

};

#endif