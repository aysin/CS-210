//
//
//Lab 2b, Rectangle.h RectangleDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef RECTANGLE_H
#define RECTANGLE_H


template  <class DataType>
class Rectangle
{ 
  private:
  DataType length;
  DataType width;
  
  public:
  bool lenOrWid ();
  void setLength (DataType l);
  void setWidth (DataType w);
  DataType getArea ();
  DataType getPerimeter ();
};

template <class DataType>
bool Rectangle<DataType>::lenOrWid()
{
  bool result;
  
  if(length > width)
    result = true;
  else
    result = false;
  
  return result;
  
}

template <class DataType>
void Rectangle<DataType>::setLength (DataType l)
{
  length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth (DataType w)
{
  width = w;
}

template <class DataType>
DataType Rectangle<DataType>::getArea ()
{
return (length*width);
} 

template <class DataType>
DataType Rectangle<DataType>::getPerimeter ()
{ 
  return ((2 * length) + (2 * width));
} 

#endif

