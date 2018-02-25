
#include "Arduino.h"
#include "InfoStation.h"

InfoStation* application;

void setup() 
{
	setUpLogger()
	application = new InfoStation();
}

void loop() 
{
  application->run();
}
