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

uint16_t ClockData::getYear() const
{
  return this->year;
}

uint8_t ClockData::getMonth() const
{
  return this->month;
}

uint8_t ClockData::getDay() const
{
  return this->day;
}

uint8_t ClockData::getHour() const
{
  return this->hour;
}

uint8_t ClockData::getMinute() const
{
  return this->minute;
}

uint8_t ClockData::getSecond() const
{
  return this->second;
}

String ClockData::getDateString() const
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

String ClockData::getDayMonthString() const
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
 
  return date;
}

String ClockData::getYearString() const
{ 
  return String(this->year);
}

String ClockData::getTimeString() const
{
  String time = String();

  if (this->getHour() < 10)
  {
    time += "0";
  }
  
  time += this->getHour();
  time += ":";
  
  if (this->getMinute() < 10)
  {
    time += "0";
  }
  
  time += this->getMinute();
 
  return time;
}
