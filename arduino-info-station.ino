
#include "Arduino.h"
#include "InfoStation.h"

InfoStation* application;

void setup() 
{
  application = new InfoStation();
}

void loop() 
{
  application->run();
}
