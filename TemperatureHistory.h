#ifndef TemperatureHistory_h
#define TemperatureHistory_h

#include "Sensors.h"

#define HISTORY_POINTS 360
#define MOV_AVG_POINTS 30

class TemperatureHistory
{
private:
	float history[HISTORY_POINTS];
	float movAvg[MOV_AVG_POINTS];
	int indexHistory;
	int indexMovAvg;

	void updateHistory(float temperature);
	
public:
	TemperatureHistory();

	void registerTemperature(const SensorData& data);
	const float* getHistory() const;
	const int& getHistoryIndex() const;
	
};

#endif