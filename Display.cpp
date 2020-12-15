#include "Display.h"

Display::Display()
{
  tft = TFT_HX8357();
  tft.begin();
  tft.setRotation(1);
  tft.setCursor(0, 0);
  tft.fillScreen(TFT_BLACK);

  initStaticParts();
  drawCurrentWeather(WeatherData());
  drawForecastWeather(WeatherData());
}

void Display::initStaticParts()
{
   tft.fillRect(0, 0, WIDTH, 40, getColor(180, 180, 200));
   
   Images::renderHumidityImage(tft, 136, 12);
   Images::renderPressureImage(tft, 4, 8);

   tft.drawFastVLine(22, 45, 105, getGrayScaleColor(0xAA));
   
   tft.setTextColor(getGrayScaleColor(0xAA)); 
   tft.setFreeFont(FSS9);
   tft.setTextSize(1);

   tft.drawString("30", 1, 45, 1);
   tft.drawString("0", 11, 115, 1);
   
   Images::renderThermometerImage(tft, 390, 80);
   
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

void Display::drawAtmosphericPressure(const SensorData& data)
{
  tft.fillRect(20, 6, 110, 27, getColor(180, 180, 200));

  tft.setTextColor(tft.color565(240, 240, 240)); 
  
  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  String pressure = String(data.getPressure(), 1);
  tft.drawString(pressure.c_str(), 20, 10, 1);
  
  tft.setFreeFont(FSS9);
  tft.setTextSize(1);
  
  uint8_t x = 82;
  if (pressure.length() > 5)
  {
     x = 95;
  }
  
  tft.drawString("hPa", x, 15, 1);
}

void Display::drawHumidity(const SensorData& data)
{
  tft.fillRect(153, 6, 65, 27, getColor(180, 180, 200));
  tft.setTextColor(tft.color565(240, 240, 240));  

  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  String humidity = String(data.getHumidity(), 1);
  tft.drawString(humidity.c_str(), 153, 10, 1);
  
  tft.setFreeFont(FSS9);
  tft.setTextSize(1);
    
  tft.drawString("%", 199, 15, 1);
}

void Display::drawTemperature(const TemperatureHistory& history, const SensorData& data)
{
	tft.fillRect(23, 40, 360, 100, getGrayScaleColor(0));
	
	tft.drawFastHLine(23, 60, 360, getGrayScaleColor(0x44));
	tft.drawFastHLine(23, 80, 360, getGrayScaleColor(0x44));
	tft.drawFastHLine(23, 100, 360, getGrayScaleColor(0x44));
	tft.drawFastHLine(23, 140, 360, getGrayScaleColor(0x44));
 
	tft.drawFastHLine(22, 120, 360, getGrayScaleColor(0xAA));
	
	const int& index = history.getHistoryIndex();
	const float* historyTemperatures = history.getHistory();

  float lastTemp = -40;
  
	for (int i = index ; i < HISTORY_POINTS ; ++i)
	{
		float temp = historyTemperatures[i];
		
		if (temp < -10)
		{
			temp = -10;
		}
		else if (temp > 40)
		{
			temp = 40;
		}

    if (lastTemp != -40)
    {
      tft.drawLine(23 + i - 1, 40 + 80 - lastTemp * 2, 23 + i, 40 + 80 - temp * 2, getColor(240, 120, 120));
    }
    else
    {
      tft.drawPixel(23 + i, 40 + 80 - temp * 2, getColor(240, 120, 120));
    }

    lastTemp = temp;
	}
	
	tft.fillRect(410, 80, 90, 30, getGrayScaleColor(0));
	
	tft.setFreeFont(FSS12);
	tft.setTextSize(1);

	tft.setTextColor(getGrayScaleColor(250));  
	tft.drawString(String(data.getTemperature1(), 1).c_str(), 410, 83, 1);
	
	tft.setFreeFont(FSS9);
	tft.drawString("C", 460, 87, 1);
	
}

void Display::drawCurrentWeather(const WeatherData& data)
{
	return;
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

void Display::drawForecastWeather(const WeatherData& data)
{
	return;
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

void Display::drawDateAndTime(const ClockData& data)
{
  tft.fillRect(230, 4, WIDTH, 28, getColor(180, 180, 200));

  tft.setFreeFont(FSS18);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(240, 240, 240));  
  tft.drawString(data.getTimeString().c_str(), 385, 5, 1);
  
  tft.setTextColor(tft.color565(60, 60, 60));  
  tft.drawString(data.getDayMonthString().c_str(), 230, 6, 1);

  tft.setFreeFont(FSS12);
  tft.setTextSize(1);

  tft.setTextColor(tft.color565(40, 40, 40));  
  tft.drawString(data.getYearString().c_str(), 320, 13, 1);
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
