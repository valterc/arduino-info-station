#include "InfoStation.h"

InfoStation::InfoStation()
{
  Serial.begin(9600);
}

void InfoStation::run()
{
  Serial.println("Reading sensors...");
  this->sensors.update();
  SensorData data = this->sensors.getData();
  Serial.print("Temperature1= ");
  Serial.print(data.getTemperature1());
  Serial.print(" Temperature2= ");
  Serial.print(data.getTemperature2());
  Serial.print(" HeatIndex= ");
  Serial.print(data.getHeatIndex());
  Serial.print(" Pressure= ");
  Serial.print(data.getPressure());
  Serial.print(" Humidity= ");
  Serial.println(data.getHumidity());
  
  delay(2000);
}

