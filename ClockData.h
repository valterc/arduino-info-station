#ifndef ClockData_h
#define ClockData_h

#include <Arduino.h>

class ClockData
{
  private:
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    
  public:
    ClockData();
    ClockData(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
    uint16_t getYear() const;
    uint8_t getMonth() const;
    uint8_t getDay() const;
    uint8_t getHour() const;
    uint8_t getMinute() const;
    uint8_t getSecond() const;

    String getDateString() const;
	  String getDayMonthString() const;
	  String getYearString() const;
    String getTimeString() const;
    
};

#endif
