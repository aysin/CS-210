//
//
//Lab 3a, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef Road_h
#define Road_h

class Road
{
private:
  double length;  // In Mile
  double width;   // In Feet
  
public:
  Road (double, double);
  void setLength(double length);
  void setWidth(double width);
  double getWidth() const;
  double getLength() const;
  double asphalt(double thickness) const;
  
};

#endif