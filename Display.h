#ifndef Display_h
#define Display_h

#include <TFT_HX8357.h>
#include "WeatherData.h"
#include "ClockData.h"
#include "SensorData.h"
#include "Images.h"
#include "TemperatureHistory.h"

#include <Fonts/GFXFF/FreeSansBold24pt7b.h>
#include <Fonts/GFXFF/FreeSans9pt7b.h>
#include <Fonts/GFXFF/FreeSans12pt7b.h>
#include <Fonts/GFXFF/FreeSans18pt7b.h>

#define FSSB24 &FreeSansBold24pt7b
#define FSS9 &FreeSans9pt7b
#define FSS12 &FreeSans12pt7b
#define FSS18 &FreeSans18pt7b

#define WIDTH 480
#define HEIGHT 320

constexpr uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue){
  return 
		(((31 * (red + 4)) / 255) << 11) | 
        (((63 * (green + 2)) / 255) << 5) | 
        ((31 * (blue + 4)) / 255);
}

constexpr uint16_t getGrayScaleColor(uint8_t amount){
  return 
		(((31 * (amount + 4)) / 255) << 11) | 
        (((63 * (amount + 2)) / 255) << 5) | 
        ((31 * (amount + 4)) / 255);
}

class Display
{
  private:
    TFT_HX8357 tft;

	void initStaticParts();
	
  public:
    Display();
    void draw();
	
    void drawInsideTemperature(const SensorData& data);
    void drawHumidity(const SensorData& data);
    void drawAtmosphericPressure(const SensorData& data);
    void drawDateAndTime(const ClockData& data);

	void drawTemperature(const TemperatureHistory& history, const SensorData& data);
	
    void drawCurrentWeather(const WeatherData& data);
    void drawForecastWeather(const WeatherData& data);
    
};

#endif
