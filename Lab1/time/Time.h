
//
//
//Lab 1b, The Times.h Program
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
  void setHour( double );   // set hour
  void setMinute( double ); // set minute
  void setSecond( double ); // set second
  double timeInHours();    //"getter"
  double timeInMinutes();  //getter
  double timeInSeconds();  // getter
};

#endif