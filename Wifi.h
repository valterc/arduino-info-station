#ifndef Wifi_h
#define Wifi_h

#include "src/ESP8266.h"

#define WIFI_PIN_RESET 8

class Wifi
{
  private:
    ESP8266 esp;

  public:
    Wifi();
    
};

#endif
