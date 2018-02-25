#ifndef WeatherData_h
#define WeatherData_h

#include <Arduino.h>

class WeatherData
{
  private:
    

  public:

    float min;
    float max;
    float current;
    String message;
    String image;
    boolean rain;
    boolean snow;
  
    WeatherData();

};

#endif
