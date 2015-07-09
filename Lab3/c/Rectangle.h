
//
//
//Lab 3b, Rectangle.h RectangleDriver.cpp Program
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
  Rectangle(); //does nothing
  Rectangle(const DataType&, const DataType&); //Constructor passes values
  
  void setLength (const DataType& l);
  void setWidth (const DataType& w);
  DataType getArea () const;
  DataType getPerimeter () const;
  bool lenOrWid () const;
};

template <class DataType>
Rectangle<DataType>::Rectangle() {}

template <class DataType>
Rectangle<DataType>::Rectangle(const DataType& w, const DataType& l)
{
  width=w;
  length=l;
}

template <class DataType>
void Rectangle<DataType>::setLength (const DataType& l)
{
  length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth (const DataType& w)
{
  width = w;
} 

template <class DataType>
DataType Rectangle<DataType>::getArea () const
{
return (length*width);
} 

template <class DataType>
DataType Rectangle<DataType>::getPerimeter () const
{ 
  return ((2 * length) + (2 * width));
} 

template <class DataType>
bool Rectangle<DataType>::lenOrWid() const
{
  bool result = true;
  
  if(width > length)
    result = false;
  
  return result;
}

#endif

