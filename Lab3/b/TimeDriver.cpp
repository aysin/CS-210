//
//
//Lab 3b, The Times.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include "Time.h"
#include "Time.h" // testing ifndef
#include <iomanip>
using namespace std;

#include <cassert>

int main()
{
  //print my name and this assignments title
  cout << "\n\nLab 3b,Time.h Time.cpp TimeDriver.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply a const.";  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  // Creating 3 objects for testing
  Time dC;  //default constructor
  Time firstTime(1, 40, 30);
 
  cout << endl;
  cout << "Testing CONSTRUCTOR (1 hour, 40 minutes, 30 seconds)" << endl;
  cout << "Expected hours: 1.675" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(3);
  cout << "Actual hours: " << firstTime.timeInHours() << endl;
  assert (firstTime.timeInHours() > 1.674 && firstTime.timeInHours() < 1.676);
  
  cout << "Expected minutes: 100.5" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout << "Actual minutes: " << firstTime.timeInMinutes() << endl;
  assert (firstTime.timeInMinutes() == 100.5);
  
  cout << "Expected seconds: 6030" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(0);
  cout << "Actual seconds: " << firstTime.timeInSeconds() << endl;
  assert (firstTime.timeInSeconds() == 6030);
  
  // Initializing first object
  firstTime.setHour(1);
  firstTime.setMinute(40);
  firstTime.setSecond(30);
  
  cout << endl;
  cout << "Testing first object (1 hour, 40 minutes, 30 seconds)" << endl;
  cout << "Expected hours: 1.675" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(3);
  cout << "Actual hours: " << firstTime.timeInHours() << endl;
  assert (firstTime.timeInHours() > 1.674 && firstTime.timeInHours() < 1.676);
  
  cout << "Expected minutes: 100.5" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout << "Actual minutes: " << firstTime.timeInMinutes() << endl;
  assert (firstTime.timeInMinutes() == 100.5);

  cout << "Expected seconds: 6030" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(0);
  cout << "Actual seconds: " << firstTime.timeInSeconds() << endl;
  assert (firstTime.timeInSeconds() == 6030);

  
  // object copy testing, with assignment UPON declaration
  {
    const Time copy = firstTime;
    
    cout << "\nObject copy testing, with assignment UPON declaration" << endl;
    cout << "Testing copy of first object (1 hour, 40 minutes, 30 seconds)" << endl;
    cout << "Expected hours: 1.675" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(3);
    cout << "Actual hours: " << copy.timeInHours() << endl;
    assert (copy.timeInHours() > 1.674 && copy.timeInHours() < 1.676);

    
    cout << "Expected minutes: 100.5" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(1);
    cout << "Actual minutes: " << copy.timeInMinutes() << endl;
    assert (copy.timeInMinutes() == 100.5);

    
    cout << "Expected seconds: 6030" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(0);
    cout << "Actual seconds: " << copy.timeInSeconds() << endl;
    assert (copy.timeInSeconds() == 6030);

  }
  
  // object copy testing, with assignment AFTER declaration
  {
    Time copy (0,0,0); copy = firstTime;
    
    cout << "\nObject copy testing, with assignment AFTER declaration" << endl;
    cout << "Testing copy of first object (1 hour, 40 minutes, 30 seconds)" << endl;
    cout << "Expected hours: 1.675" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(3);
    cout << "Actual hours: " << copy.timeInHours() << endl;
    assert (copy.timeInHours() > 1.674 && copy.timeInHours() < 1.676);
    
    cout << "Expected minutes: 100.5" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(1);
    cout << "Actual minutes: " << copy.timeInMinutes() << endl;
    assert (copy.timeInMinutes() == 100.5);
    
    cout << "Expected seconds: 6030" << endl;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(0);
    cout << "Actual seconds: " << copy.timeInSeconds() << endl;
    assert (copy.timeInSeconds() == 6030);

  }
  
  cout << endl;
}
