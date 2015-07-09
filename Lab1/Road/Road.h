//
//
//Lab 1a, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef Road_h
#define Road_h

class Road
{
private:
  float length;  // In Mile
  float width;   // In Feet
  
public:
  void setLength(double length);
  void setWidth(double width);
  double getWidth();
  double getLength();
  double asphalt(double thickness);
  
};

#endif