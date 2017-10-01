#include "SensorData.h"

SensorData::SensorData()
{
}

SensorData::SensorData(float temperature1, float temperature2, float heatIndex, float pressure, float humidity) : 
  temperature1(temperature1), temperature2(temperature2), heatIndex(heatIndex), pressure(pressure), humidity(humidity)
{
}

float SensorData::getTemperature1()
{
  return this->temperature1;
}

float SensorData::getTemperature2()
{
  return this->temperature2;
}

float SensorData::getHeatIndex()
{
  return this->heatIndex;
}

float SensorData::getPressure()
{
  return this->pressure;
}

float SensorData::getHumidity()
{
  return this->humidity;
}

