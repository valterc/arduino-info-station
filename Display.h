#ifndef Display_h
#define Display_h

#include <TFT_HX8357.h>
#include "WeatherData.h"

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

class Display
{
  private:
    TFT_HX8357 tft;

  public:
    Display();
    void draw();

    void initTopBar();
    void drawInsideTemperature();
    void drawHumidity();
    void drawAtmosphericPressure();

    void drawDateAndTime(ClockData data);

    void drawCurrentWeather(WeatherData data);
    void drawForecastWeather(WeatherData data);
    
};

#endif
