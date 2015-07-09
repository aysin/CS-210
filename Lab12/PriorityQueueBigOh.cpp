//
//
//Lab 12b, PriorityQueueBigOh.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <string>
using namespace std;

#include <cassert>      //for assert
#include <cmath>        //for log and pow
#include <ctime>        //for clock() and clock_

#include "PriorityQueue.h"

int main()
{
  cout << "\n\nLab 12b, PriorityQueueBigOh.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply 12b, PriorityQueueBigOh and get values with BigO().\n";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  const int REPS = 100000; // for timing fast operations, use REPS up to 100th of the starting n
  int n = 10000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  
  
  cout << "\nEnqueue() O(log n)\n" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    //Declare PQ
    PriorityQueue<int> List;
    
    //Go thru loop to enter values
    for (int i = n; i > 0; i--)
      List.enqueue(i);
    
    clock_t startTime = clock();  // start the timer
    
    assert(List.getSize() == n);
    
    for(int j = 0; j < REPS; j++ )
      List.enqueue(n + j);
    assert(List.getSize() == n + REPS);
    
    clock_t endTime = clock(); //stop time
    
    for (int i = 0; i < List.getSize(); i++)
    {
      int first = List.dequeue();
      int second = List.dequeue();
      assert(first >= second);
    }
    
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
    cout << " for n = " << n << endl;
  }
  
  {
    const int REPS = 10000; // for timing fast operations, use REPS up to 100th of the starting n
    int n = 1000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
    
    cout << "\nDequeue() O(log n)\n" << endl;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      
      PriorityQueue<int> List;
      for(int i = n; i > 0; i--)
        List.enqueue(i);
      assert(List.getSize() == n);
      
      //start timing
      clock_t startTime = clock();
      for(int j = 0; j < REPS; j++)
        List.dequeue();
      clock_t endTime = clock(); //stop timign
      assert(List.getSize() == n - REPS);
      
      for (int i = 0; i < List.getSize(); i++)
      {
        int first = List.dequeue();
        int second = List.dequeue();
        assert(first >= second);
      }
      
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
      
      // reporting block
      cout << elapsedTimeTicks;;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n = " << n << endl;
    }}
  
}

