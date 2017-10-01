#include "Display.h"

Display::Display()
{
  tft = TFT_HX8357();
  tft.begin();
  tft.setRotation(1);
  tft.setCursor(0, 0);
  tft.fillScreen(TFT_BLACK);

  initTopBar();
  drawCurrentWeather(WeatherData());
  drawForecastWeather(WeatherData());
}

void Display::initTopBar()
{
   tft.fillRect(0, 0, WIDTH, 40, TFT_CYAN);
}

void Display::drawCurrentWeather(WeatherData data)
{

  // Draw image

  tft.fillRect(100, 100, 64, 64, TFT_CYAN);

  // Draw Current temperature
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setFreeFont(FSSB24);
  tft.setTextSize(1);
  tft.drawString("20 C", 180, 115, 1);

  // Draw state message

  tft.setFreeFont(FSS9);
  tft.setTextSize(1);
  tft.drawString("Rain showers and heavy thunderstorms", 100, 175, 1);

  // Draw min and max temperatures

  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString("21 C", 300, 105, 1);

  tft.setTextColor(tft.color565(210, 210, 210)); 
  tft.drawString("7 C", 300, 135, 1);
  
}

void Display::drawForecastWeather(WeatherData data)
{
  // Draw image

  tft.fillRect(100, HEIGHT - 64, 64, 64, TFT_CYAN);

  // Draw tomorrow date

  tft.setTextColor(TFT_WHITE); 
  tft.setFreeFont(FSS12);
  tft.setTextSize(1);
  tft.drawString("15/06/2017", 175, HEIGHT - 64, 1);

  // Draw min and max temperatures

  tft.setFreeFont(FSS18);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(210, 210, 210));  
  tft.drawString("06 C", 175, HEIGHT - 32, 1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString("23 C", 260, HEIGHT - 32, 1);
  
}

void Display::draw()
{
  int width = tft.textWidth("Hello World!", 2);
  int height = tft.fontHeight(2);
  
  //tft.fillRect(10, 10, width, height, TFT_BLACK);
  //tft.setCursor(loop, 0);
  //tft.setTextColor(TFT_CYAN);
  //tft.drawString("Sin", 5, 15,2);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setFreeFont(FSSB24);
  tft.setTextColor(TFT_BLACK);  
  tft.setTextSize(1);
  tft.drawString("17.5 C", 10, 10, 0);
  

  tft.drawLine(120, 10, 140, 20, TFT_GREEN);

}
