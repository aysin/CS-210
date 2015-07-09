//
//
//Lab 3b, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include "Time.h"

Time::Time () {} //Retunrs nothing

Time::Time (double h, double m, double s)
{
  hour = h;
  minute = m;
  second = s;
} //Constructor

// Set the hour value
void Time::setHour( double h )
{ hour = ( h >= 0 && h < 24 ) ? h : 0; }

// Set the minute value
void Time::setMinute( double m )
{ minute = ( m >= 0 && m < 60 ) ? m : 0; }

// Set the second value
void Time::setSecond( double s )
{ second = ( s >= 0 && s < 60 ) ? s : 0; }

double Time::timeInSeconds() const
{
  return hour * 60 * 60 + minute * 60 + second;
}

double Time::timeInHours() const
{
  return hour + minute / 60 + second / 3600;
}

double Time::timeInMinutes() const
{
  return hour * 60 + minute + second / 60;
}

