//
//
//Lab 1b, The Times.h Program
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
  cout << "\n\nLab 1b,Time.h Time.cpp TimeDriver.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: Time.cpp Takes time and";
  cout << "prints out time in hours, time in minute, times in seconds.\n\n";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  // Creating 3 objects for testing
  Time firstTime;
  Time secondTime;
  Time thirdTime;
  
  // Initializing first object
  firstTime.setHour(1);
  firstTime.setMinute(40);
  firstTime.setSecond(30);
  
  // Initializing second object
  secondTime.setHour(5);
  secondTime.setMinute(10);
  secondTime.setSecond(15);
  
  // Initializing third object
  thirdTime.setHour(2);
  thirdTime.setMinute(24);
  thirdTime.setSecond(56);
  
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

  
  cout << "\nTesting second object (5 hours, 10 minutes, 15 seconds)" << endl;
  cout << "Expected hours: 5.17083" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(5);
  cout << "Actual hours: " << secondTime.timeInHours() << endl;
  assert (secondTime.timeInHours() > 5.17082 && secondTime.timeInHours() < 5.17084);

  cout << "Expected minutes: 310.25" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "Actual minutes: " << secondTime.timeInMinutes() << endl;
  assert (secondTime.timeInMinutes() > 310.24 && secondTime.timeInMinutes() < 310.26);

  cout << "Expected seconds: 18615" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(0);
  cout << "Actual seconds: " << secondTime.timeInSeconds() << endl;
  assert (secondTime.timeInSeconds() == 18615);

  
  cout << "\nTesting third object (2 hours, 24 minutes, 56 seconds)" << endl;
  cout << "Expected hours: 2.41556" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(5);
  cout << "Actual hours: " << thirdTime.timeInHours() << endl;
  assert (thirdTime.timeInHours() > 2.41555 && thirdTime.timeInHours() < 2.41557);
  
  cout << "Expected minutes: 144.933" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(3);
  cout << "Actual minutes: " << thirdTime.timeInMinutes() << endl;
  assert (thirdTime.timeInMinutes() > 144.932 && thirdTime.timeInMinutes() < 144.934);
  
  cout << "Expected seconds: 8696" << endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(0);
  cout << "Actual seconds: " << thirdTime.timeInSeconds() << endl;
  assert (thirdTime.timeInSeconds() == 8696);
  
  // object copy testing, with assignment UPON declaration
  {
    Time copy = firstTime;
    
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
    Time copy;
    copy = firstTime;
    
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
