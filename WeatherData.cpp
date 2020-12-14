#include "WeatherData.h"

WeatherData::WeatherData(float min, float max, float current, String& message, String& image, boolean rain, boolean snow)
{
	this->min = min;
	this->max = max;
	this->current = current;
	this->message = message;
	this->image = image;
	this->rain = rain;
	this->snow = snow;
}

float WeatherData::getMin()
{
	return min;
}

float WeatherData::getMax()
{
	return max;
}

float WeatherData::getCurrent()
{
	return current;
}

String& WeatherData::getMessage()
{
	return message;
}

String& WeatherData::getImageName()
{
	return image;
}

boolean WeatherData::isRaining()
{
	return rain;
}

boolean WeatherData::isSnowing()
{
	return snow;
}