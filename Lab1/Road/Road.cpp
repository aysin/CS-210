//
//
//Lab 1a, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal


#include "Road.h"

void Road::setLength(double len)
{
  length = len;
}

void Road::setWidth(double wid)
{
  width = wid;
}

double Road::getLength()
{
  return length;
}

double Road::getWidth()
{
  return width;
}


double Road::asphalt(double thickness)
{
  //gets the value as inches
  return (length * width * 5280 * thickness)/12;
  
}

