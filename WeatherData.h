#ifndef WeatherData_h
#define WeatherData_h

#include <Arduino.h>

class WeatherData
{
  private:
    float min;
    float max;
    float current;
    String message;
    String image;
    boolean rain;
    boolean snow;

  public:
    WeatherData() = default;
	WeatherData(float min, float max, float current, String& message, String& image, boolean rain, boolean snow);
	
	float getMin();
	float getMax();
	float getCurrent();
	String& getMessage();
	String& getImageName();
	boolean isRaining();
	boolean isSnowing();
	
};

#endif
