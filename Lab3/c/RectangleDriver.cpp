 //
//
//Lab 3c, Rectangle.h RectangleDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
using namespace std;

#include <cassert>
#include "Rectangle.h"
#include "Rectangle.h" //ifndef test



int main()
{
  cout << "\n\nLab 3c,(CONST) Rectangle.h RectangleDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply a const.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  Rectangle <float> dC; // default constructor
  Rectangle<float> bx (36.7, 15) ; //setLength ; setWidth
  cout << "\n\nTESTING CONSTRUCTOR\n";

  // Testing float for DataType
  cout << "Length: 15 AND Width: 36.7\n";
  cout << "\nValue for area is " << bx.getArea() << endl;
  cout << "Expected value for area is 550.5\n";
  assert ( bx.getArea() > 550.4 &&  bx.getArea() < 550.6);
  cout << "\nValue for perimeter is " << bx.getPerimeter() << endl;
  cout << "Expected value for perimeter is 103.4\n";
  assert ( bx.getPerimeter() > 103.3 && bx.getPerimeter() < 103.5 );
  cout << "\nTesting the length and width comparison\n";
  if(bx.lenOrWid ())
    cout << "Length is greater than width " << endl;
  else
    cout << "Width is greater than length " << endl;
  cout << "Expected result width is greater than length\n\n";
  
  Rectangle<float> box ; //setLength ; setWidth
  box.setLength (15);  //Testing with new Numbers
  box.setWidth (36.7);  //Testing with new Numbers
  
  //Testing first elements LENGHT-WIDTH-AREA-PERIMETER
  cout << "\n\nTesting FLOAT DataType \n";
  
  // Testing float for DataType
  cout << "Length: 15 AND Width: 36.7\n";
  cout << "\nValue for area is " << box.getArea() << endl;
  cout << "Expected value for area is 550.5\n";
  assert ( box.getArea() > 550.4 &&  box.getArea() < 550.6);
  cout << "\nValue for perimeter is " << box.getPerimeter() << endl;
  cout << "Expected value for perimeter is 103.4\n";
  assert ( box.getPerimeter() > 103.3 && box.getPerimeter() < 103.5 );
  cout << "\nTesting the length and width comparison\n";
  if(box.lenOrWid ())
    cout << "Length is greater than width " << endl;
  else
    cout << "Width is greater than length " << endl;
  cout << "Expected result width is greater than length\n\n";

  // object copy testing, with assignment Upon decleration
  {
    const Rectangle<float> copy = box;
    
    //Testing first elements LENGHT-WIDTH-AREA-PERIMETER
    cout << "\nObject copy testing, with assignment UPON declaration\n" << endl;
    cout << "Value for area is " << copy.getArea() << endl;
    cout << "Expected value for area is 550.5\n";
    assert ( copy.getArea() > 550.4 &&  copy.getArea() < 550.6);
    
    cout << "\nValue for perimeter is " << copy.getPerimeter() << endl;
    cout << "Expected value for perimeter is 103.4\n";
    assert ( copy.getPerimeter() > 103.3 && copy.getPerimeter() < 103.5 );
    
    if(copy.lenOrWid ())
      cout << "\nLength is greater than width " << endl;
    else
      cout << "\nWidth is greater than length " << endl;
    cout << "Expected result width is greater than length\n\n";
  }
  
 // object copy testing, with assignment AFTER decleration
  {
    Rectangle<float> copy(0,0); copy = box;
    
    cout << "\nObject copy testing, with assignment AFTER declaration\n" << endl;
    cout << "Value for area is " << copy.getArea() << endl;
    cout << "Expected value for area is 550.5\n";
    assert ( copy.getArea() > 550.4 &&  copy.getArea() < 550.6);
    
    cout << "\nValue for perimeter is " << copy.getPerimeter() << endl;
    cout << "Expected value for perimeter is 103.4\n";
    assert ( copy.getPerimeter() > 103.3 && copy.getPerimeter() < 103.5 );
    
    if(copy.lenOrWid ())
      cout << "\nLength is greater than width " << endl;
    else
      cout << "\nWidth is greater than length " << endl;
    cout << "Expected result width is greater than length\n\n";
  }
  
}
