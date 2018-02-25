#include "InfoStation.h"

InfoStation::InfoStation()
{
}

void InfoStation::run()
{
  Serial.println("Reading sensors...");
  this->sensors.update();
  SensorData data = this->sensors.getData();
this->display.draw
  logInfo("Temperature1= ");
  
  //Serial.print("Temperature1= ");
  Serial.print(data.getTemperature1());
  Serial.print(" Temperature2= ");
  Serial.print(data.getTemperature2());
  Serial.print(" HeatIndex= ");
  Serial.print(data.getHeatIndex());
  Serial.print(" Pressure= ");
  Serial.print(data.getPressure());
  Serial.print(" Humidity= ");
  Serial.println(data.getHumidity());
  
  Serial.println("Reading RTC...");
  this->rtc.update();
  
  ClockData clockData = this->rtc.getData();
  
  Serial.print("Year= ");
  Serial.print(clockData.getYear());
  Serial.print(" Month= ");
  Serial.print(clockData.getMonth());
  Serial.print(" Day= ");
  Serial.print(clockData.getDay());
  Serial.print(" Hour= ");
  Serial.print(clockData.getHour());
  Serial.print(" Minute= ");
  Serial.println(clockData.getMinute());
  
  String date = String();
  
  date += clockData.getYear();
  date += "-";
  
  if (clockData.getMonth() < 10)
  {
    date += "0";
  }
  
  date += clockData.getMonth();
  date += "-";
  
  if (clockData.getDay() < 10)
  {
    date += "0";
  }
  
  date += clockData.getDay();
  
  Serial.print("Date as String: ");
  Serial.println(date);
  
  delay(2000);
}

