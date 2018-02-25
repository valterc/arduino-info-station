#include "ClockData.h"

ClockData::ClockData()
{
}

ClockData::ClockData(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->minute = minute;
  this->second = second;
}

uint16_t ClockData::getYear()
{
  return this->year;
}

uint8_t ClockData::getMonth()
{
  return this->month;
}

uint8_t ClockData::getDay()
{
  return this->day;
}

uint8_t ClockData::getHour()
{
  return this->hour;
}

uint8_t ClockData::getMinute()
{
  return this->minute;
}

uint8_t ClockData::getSecond()
{
  return this->second;
}

String ClockData::getDateString()
{
  String date = String();

  if (this->getDay() < 10)
  {
    date += "0";
  }
  
  date += this->getDay();
  date += "/";
  
  if (this->getMonth() < 10)
  {
    date += "0";
  }
  
  date += this->getMonth();
  date += "/";
  
  date += this->getYear();
 
  return date;
}


