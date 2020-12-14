#ifndef Wifi_h
#define Wifi_h

#include "Arduino.h"
#include "Logger.h"
#include "src/ESP8266.h"
#include "Secrets.h"
#include "WeatherData.h"
#include "ForecastData.h"
#include "ClockData.h"

#define WIFI_PIN_RESET 8
#define WIFI_PIN_EN    9

#define WEATHER_API_CURRENT_WEATHER "http://api.openweathermap.org/data/2.5/weather?id=6458783&units=metric&appid="
#define WEATHER_API_FORECAST		"http://api.openweathermap.org/data/2.5/forecast?id=6458783&units=metric&appid="

class Wifi
{
  private:
    ESP8266 esp;
	WeatherData weatherData;
	ForecastData forecastData;
	
  public:
    Wifi();
	
	void update(ClockData clockData);
	
	WeatherData& getWeatherData();
	ForecastData& getForecastData();
	
};

#endif
