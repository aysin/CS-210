
//
//
//Lab 9b Sort.cpp
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal


#include <iostream> // for cout and endl
#include <string> // for string
#include <algorithm> // for sort
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

int main()
{
  // problem setup goes here
  srand((int)time(0));
  rand();
  long elapsedTimeTicksNorm = 0;
  long expectedTimeTicks = 0;
  
  // programmer customizations go here
  int n = 500000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  
  // for parsing the inputfile
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    //create dynamic array
    double* array = new double[n];
    
    // more problem setup goes here -- the stuff not timed
    for (int i = 0; i < n; i++)
    {
      int j = 0;
      j = rand();
      array[i] = j;
    }
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    //sort array by using sort algorithm
    sort(array, array +n);
    
    //end time
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    for(int i = 1; i <n; i++)
      assert(array[i - 1] <= array[i]);
    
    //deallocate array
    delete [] array;
    
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
    cout << " for n=" << n << endl;
  } }
