//
//
//Lab 3a, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include "Road.h"

Road::Road (double wid, double len)
{
  width = wid;
  length = len;
}

void Road::setLength(double len)
{
  length = len;
}

void Road::setWidth(double wid)
{
  width = wid;
}

double Road::getLength() const
{
  return length;
}

double Road::getWidth() const
{
  return width;
}


double Road::asphalt(double thickness) const
{
  //gets the value as inches
  return ((length * 63360 ) * (width * 12) * thickness)/1728;
  
}

