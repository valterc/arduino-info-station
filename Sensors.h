#ifndef Sensors_h
#define Sensors_h

#include <Wire.h>
#include <SPI.h>
#include "src/Adafruit_Sensor.h"
#include "src/Adafruit_BMP280.h"
#include "src/DHT.h"

#include "SensorData.h"

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

#define DHTPIN 2     
#define DHTTYPE DHT22 

class Sensors
{
  private:
    DHT dht;
    Adafruit_BMP280 bme;

    SensorData data;
    
  public:
    Sensors();
    void update();
    SensorData getData();

};

#endif
