#include "Wifi.h"

Wifi::Wifi() : esp(Serial1)
{
	pinMode(WIFI_PIN_RESET, OUTPUT);
	pinMode(WIFI_PIN_EN, OUTPUT);

	digitalWrite(WIFI_PIN_RESET, 1);
	digitalWrite(WIFI_PIN_EN, 1);

	Serial1.begin(115200);
	delay(100);
	
	logInfoLine(String(WEATHER_API_CURRENT_WEATHER) += WEATHER_API_KEY)
	logInfoLine(String(WEATHER_API_FORECAST) += WEATHER_API_KEY)

	logInfoLine("Setting Up Wifi")
	logInfoLine("FW Version:")
	logInfoLine(esp.getVersion().c_str())
  
	if (esp.setOprToStationSoftAP()) 
	{
		logInfoLine("To station + softap ok")
	} 
	else 
	{
		logInfoLine("To station + softap err")
	}
	
    if (esp.joinAP(WIFI_SSID, WIFI_PASSWORD)) 
	{
        logInfoLine("Join AP success")
        logInfo("IP:")
        appendLogInfoLine(esp.getLocalIP().c_str())     
    } 
	else 
	{
        logInfoLine("Join AP failure")
    }
  
}

void Wifi::update(ClockData clockData)
{
	
}
	
WeatherData& Wifi::getWeatherData()
{
	
}

ForecastData& Wifi::getForecastData()
{
	
}	