#include "TemperatureHistory.h"

TemperatureHistory::TemperatureHistory()
{
	indexHistory = HISTORY_POINTS;
	indexMovAvg = 0;
}

void TemperatureHistory::registerTemperature(const SensorData& data)
{
	movAvg[indexMovAvg++] = data.getTemperature1();
	
	if (indexHistory != 0 || indexMovAvg == MOV_AVG_POINTS)
	{
		float tempSum = 0;
		
		for (int i = 0; i < MOV_AVG_POINTS; ++i)
		{
			tempSum += movAvg[i];
		}
		
		tempSum /= MOV_AVG_POINTS;
		
		updateHistory(tempSum);
		indexMovAvg = 0;
	}
}

void TemperatureHistory::updateHistory(float temperature)
{	
	if (indexHistory != 0)
	{
		--indexHistory;
		memcpy(history + indexHistory, history + indexHistory + 1, sizeof(float) * (HISTORY_POINTS - indexHistory + 1));
	} 
	else 
	{
		memcpy(history, history + 1, sizeof(float) * (HISTORY_POINTS - 1));
	}
	
	history[HISTORY_POINTS - 1] = temperature;
}

const float* TemperatureHistory::getHistory() const 
{
	return history;
}

const int& TemperatureHistory::getHistoryIndex() const
{
	return indexHistory;
}
