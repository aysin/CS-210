#include <iostream> // for cout and endl
#include <string> // for string
#include <fstream>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstring>

int main()
{
  // problem setup goes here
  ifstream fin;
	string line;
	char* token;
	char buf[100];
	const char* const tab = "\t";
  
  // programmer customizations go here
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n
  
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    
    // open the input file
    
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";
    
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    // read the input file
    while (fin.good())
    {
      // read the line
      getline(fin, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;
      
  	  // parse the line
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; // invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));
    }
    
    fin.close();
    // do something where n is the "size" of the problem
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    
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