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

uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue){
  return (((31*(red+4))/255)<<11) | 
               (((63*(green+2))/255)<<5) | 
               ((31*(blue+4))/255);
}

void Display::initTopBar()
{
   tft.fillRect(0, 0, WIDTH, 40, getColor(160, 160, 160));

/*
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 10, 1, 10, getColor(i, 0, 0));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 20, 1, 10, getColor(0, i, 0));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 30, 1, 10, getColor(0, 0, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 40, 1, 10, getColor(i, i, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 50, 1, 10, getColor(i, i, 0));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 60, 1, 10, getColor(0, i, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 70, 1, 10, getColor(i, 0, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 80, 1, 10, getColor(i, 128, 128));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 90, 1, 10, getColor(128, 128, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 100, 1, 10, getColor(128, i, 128));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 110, 1, 10, getColor(i, i, 128));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 120, 1, 10, getColor(128, i, i));
   }
   for (uint16_t i = 0 ; i <= 255 ; i += 1)
   {
      tft.fillRect(i, 130, 1, 10, getColor(i, 128, i));
   }
*/
}

void Display::drawAtmosphericPressure()
{
  
}

void Display::drawCurrentWeather(WeatherData data)
{
  // Clear background
  tft.fillRect(20, 120, WIDTH, 95, TFT_BLACK);
  
  // Draw image
  tft.fillRect(20, 120, 64, 64, TFT_CYAN);

  // Draw Current temperature
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setFreeFont(FSSB24);
  tft.setTextSize(1);
  tft.drawString("20 C", 100, 135, 1);

  // Draw state message

  tft.setFreeFont(FSS9);
  tft.setTextSize(1);
  tft.drawString("Rain showers and heavy thunderstorms", 20, 195, 1);

  // Draw min and max temperatures

  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString("21 C", 220, 125, 1);

  tft.setTextColor(tft.color565(210, 210, 210)); 
  tft.drawString("7 C", 220, 155, 1);
  
}

void Display::drawForecastWeather(WeatherData data)
{
  // Clear background
  tft.fillRect(20, HEIGHT - 90, WIDTH, 95, TFT_BLACK);
  
  // Draw image
  tft.fillRect(20, HEIGHT - 90, 64, 64, TFT_CYAN);

  // Draw tomorrow date

  tft.setTextColor(TFT_WHITE); 
  tft.setFreeFont(FSS12);
  tft.setTextSize(1);
  tft.drawString("15/06/2017", 95, HEIGHT - 85, 1);

  // Draw state message

  tft.setFreeFont(FSS9);
  tft.setTextSize(1);
  tft.drawString("Rain showers and heavy thunderstorms", 20, HEIGHT - 20, 1);

  // Draw min and max temperatures

  tft.setFreeFont(FSS18);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(210, 210, 210));  
  tft.drawString("06 C", 95, HEIGHT - 55, 1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString("23 C", 180, HEIGHT - 55, 1);

}

void Display::drawDateAndTime(ClockData data)
{

  tft.fillRect(220, 7, WIDTH, 20, getColor(160, 160, 160));

  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString(data.getDateString().c_str(), 220, 7, 1);
  
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
