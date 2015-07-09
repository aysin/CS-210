
//
//
//Lab 3b, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef TIME_H
#define TIME_H

class Time
{
private:
	double hour;
	double minute;
	double second;
  
public:
  Time();  // do nothing
  Time(double, double, double); // passses and initilizes variables
  void setHour( double );   // set hour
  void setMinute( double ); // set minute
  void setSecond( double ); // set second
  double timeInHours() const;    //"getter"
  double timeInMinutes() const;  //getter
  double timeInSeconds() const;  // getter
};

#endif