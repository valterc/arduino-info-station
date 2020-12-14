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

    float getTemperature1() const;
    float getTemperature2() const;
    float getHeatIndex() const;
    float getPressure() const;
    float getHumidity() const;

};

#endif
