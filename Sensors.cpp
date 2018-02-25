#include "Sensors.h"

Sensors::Sensors() : dht(DHTPIN, DHTTYPE)
{
  this->dht.begin();
  this->bme.begin();
}

void Sensors::update()
{
  float temperature2 = this->bme.readTemperature();
  float pressure = this->bme.readPressure() * 0.01;

  float humidity = this->dht.readHumidity();
  float temperature1 = this->dht.readTemperature();
  float heatIndex = this->dht.computeHeatIndex(temperature1, humidity, false);

  this->data = SensorData(temperature1, temperature2, heatIndex, pressure, humidity);
}

SensorData Sensors::getData()
{
  return this->data;
}

