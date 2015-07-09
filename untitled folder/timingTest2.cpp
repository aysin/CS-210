#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

int compareInt(const void* pa, const void* pb)
{
  // convert argument variables into something recognizable
  const int& a = *static_cast<const int*>(pa);
  const int& b = *static_cast<const int*>(pb);

  // compare ints
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

int main()
{
  // problem setup goes here

  // programmer customizations go here
  int n = 500000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    int* data = new int[n];    

    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    qsort(data, n, sizeof(int), compareInt);
    clock_t endTime = clock(); 

    // validation block -- assure that process worked
    for (int i = 1; i < n; i++)
      assert(data[i-1] <= data[i]);

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

    delete [] data;
} }
