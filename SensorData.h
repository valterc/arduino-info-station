#ifndef SensorData_h
#define SensorData_h


class SensorData
{
  private:
    float temperature1;
    float temperature2;
    float heatIndex;
    float pressure;
    float humidity;
    
  public:
    SensorData();
    SensorData(float temperature1, float temperature2, float heatIndex, float pressure, float humidity);

    float getTemperature1();
    float getTemperature2();
    float getHeatIndex();
    float getPressure();
    float getHumidity();

};

#endif
