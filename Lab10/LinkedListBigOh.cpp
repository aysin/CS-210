//
//
//Lab 10c, LinkedListBigOh.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <string>
using namespace std;

#include <cassert>      //for assert
#include <cmath>        //for log and pow
#include <ctime>        //for clock() and clock_
#include <cstdlib>      //header for srand and rand

#include "LinkedList.h"

int main()
{
  cout << "\n\nLab 10c, LinkedListBigOh.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply LinkedList and get values with BigO().";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  const int REPS = 1000000; // for timing fast operations, use REPS up to 100th of the starting n
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  srand (time(0));
  rand();
  
  cout << "\noperator[] assignment at zeroth index, O(1)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    LinkedList<double> List;
    for (int i = 0; i < n; i++)
      List.insert(rand());
    
    clock_t startTime = clock();  // start the timer
    
    for(int j = 0; j < REPS; j++ )
      List[0] = rand();
    
    clock_t endTime = clock(); //stop time
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  cout << "\noperator[] assignment at 100th index, O(1)" << endl;
  n = 50000;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    
    LinkedList<double> List;
    
    for (int i = 0; i < n; i++)
      List.insert(rand());
    
    clock_t startTime = clock();  // start the timer
    
    for( int i = 0; i < REPS; i++ )
      List[100] = rand();
    
    clock_t endTime = clock(); //stop time
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  cout << "\niteration from first to last using operator[], O(n)" << endl;
  n = 500000;
  bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    
    LinkedList<double> List;
    
    for (int i = 0; i < n; i++)
      List.insert(rand());
    
    clock_t startTime = clock();  // start the timer
    
    for(int i = 0; i < List.length(); List[i], i++);
    
    clock_t endTime = clock(); //stop time
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  cout << "\nlength, O(1)" << endl;
  n = 500000;
  bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    
    LinkedList<double> List;
    for (int i = 0; i < n; i++)
      List.insert(rand());
    
    clock_t startTime = clock();  // start the timer
    for (int reps = 0; reps < REPS; reps++)
      List.length();
    clock_t endTime = clock(); //stop time
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
}

