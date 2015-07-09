//
//
//Lab 3a, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal


#include <iostream>
#include <iomanip>
#include "Road.h"
#include "Road.h" // testing ifndef
using namespace std;

#include <cstdlib>
#include <cassert>

int main()
{
  //print my name and this assignments title
  cout << "\n\nLab 3a,Road.h Road.cpp RoadDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: Using const \n\n";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  //create object
  Road road = Road(20.25, 15.5);
  
  //initlizating the objects
  
  //test setLenght function
  cout << "\nConstructor Values are 15.5 miles and 20.25 feet\n";
  cout << "\nTesting setLength\n";
  cout << "Expected length: 15.5 miles \n";
  cout << "Actual length is " << road.getLength() << " miles"  << endl;
  assert ( road.getLength() > 15.4 && road.getLength() < 15.6);

  //test setWidth function
  cout << "\nTesting setWidth\n";
  cout << "Expected width: 20.25 feet \n";
  cout << "Actual width is " << road.getWidth() << " feet" << endl;
  assert ( road.getWidth() > 20.24 && road.getWidth() < 20.26);
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(3);
  cout << "\nTesting asphalt" << endl;
  cout << "Actual Volume is 1484628.750 cubic feet\n";
  cout << "Expected volume is " << road.asphalt(10.75) << " cubic feet\n";
  assert ( road.asphalt(10.75) > 1484628.749 && road.asphalt(10.75) < 1484628.751);
  
  //initlizating the objects
  road.setLength(15.5);  // set the length to a number in miles
  road.setWidth(20.25);  // set the width to a number in feet
  road.asphalt(10.75); //set the thickness of asphalt in inches
  
  //test setLenght function
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout << "\nTesting Road Class are 15.5 miles and 20.25 feet\n";
  cout << "\nTesting setLenght\n";
  cout << "Actual length: 15.5 miles \n";
  cout << "Expected length is " << road.getLength() << " miles"  << endl;
  assert ( road.getLength() > 15.4 && road.getLength() < 15.6);
  
  //test setWidth function
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "\nTesting setWidth\n";
  cout << "Actual width: 20.25 feet \n";
  cout << "Expected width is " << road.getWidth() << " feet" << endl;
  assert ( road.getWidth() > 20.24 && road.getWidth() < 20.26);
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(3);
  cout << "\nTesting asphalt" << endl;
  cout << "Actual Volume is 1484628.750 cubic feet\n";
  cout << "Expected volume is " << road.asphalt(10.75) << " cubic feet\n";
  assert ( road.asphalt(10.75) > 1484628.749 && road.asphalt(10.75) < 1484628.751);
  
  // object copy testing, with assignment UPON declaration
  {
    //test setLenght function
    
    const Road copy = road;
    cout << "\nObject copy testing, with assignment UPON declaration" << endl;
    cout << "\nTesting setLenght\n";
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(1);
    cout << "Expected length: 15.5 miles \n";
    cout << "Actual length is " << copy.getLength() << " miles"  << endl;
    assert ( copy.getLength() > 15.4 && copy.getLength() < 15.6);
    
    cout << "\nTesting setWidth\n";
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout << "Expected width: 20.25 feet \n";
    cout << "Actual width is " << copy.getWidth() << " feet" << endl;
    assert ( copy.getWidth() > 20.24 && copy.getWidth() < 20.26);
    
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(3);
    cout << "\nTesting asphalt" << endl;
    cout << "Actual Volume is 1484628.750 cubic feet\n";
    cout << "Expected volume is " << copy.asphalt(10.75) << " cubic feet\n";
    assert ( copy.asphalt(10.75) > 1484628.749 && copy.asphalt(10.75) < 1484628.751);
  }
  
  // object copy testing, with assignment AFTER declaration
  {
    Road copy(0,0); copy = road;
    cout << "\nObject copy testing, with assignment AFTER declaration" << endl;
    cout << "\nTesting setLenght\n";
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(1);
    cout << "Expected length: 15.5 miles \n";
    cout << "Actual length is " << copy.getLength() << " miles"  << endl;
    assert ( copy.getLength() > 15.4 && copy.getLength() < 15.6);
    
    cout << "\nTesting setWidth\n";
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    cout << "Expected width: 20.25 feet \n";
    cout << "Actual width is " << copy.getWidth() << " feet" << endl;
    assert ( copy.getWidth() > 20.24 && copy.getWidth() < 20.26);
    
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(3);
    cout << "\nTesting asphalt" << endl;
    cout << "Actual Volume is 1484628.750 cubic feet\n";
    cout << "Expected volume is " << copy.asphalt(10.75) << " cubic feet\n";
    assert ( copy.asphalt(10.75) > 1484628.749 && copy.asphalt(10.75) < 1484628.751);
  }
  
  

}