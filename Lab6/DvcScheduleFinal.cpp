// Term Project - DvcScheduleFinal.cpp
// Programmer: Aysin Oruz
// Editor: Xcode, JNote
// Compiler: Xcode, Terminal


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
  cout << "\n\nTerm Project -  DvcScheduleFinal.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create map and apply our  DvcScheduleFinal.cpp file.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  // Program information
  
  map<string, map<string, int> > subjectCodesMap; // Map of maps
  map<string, map<string, int> >::iterator it; // First iterator used for printing map contents
  map<string, int>::iterator it2; // Second iterator used for printing map contents
  
  // For parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  // Open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // Start the time!
  clock_t startTime = clock();
  
  // Read the input file
  while (fin.good())
  {
    // Read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    // Parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    const string subjectNum(course.begin() + course.find('-'), course.end());
    
    // Add the value at the subject code key value and increment its count
    subjectCodesMap[subjectCode][subjectNum]++;
  }
  
  // Close the file
  fin.close();
  
  // STL maps handle sorting automatically, so all courses and subjects are already in alphabetical order
  // Print all subjects, courses, and their counts
  for (it = subjectCodesMap.begin(); it != subjectCodesMap.end(); it++)
  {
    cout << it->first << ", " << subjectCodesMap[it->first].size() << " course(s)" << endl;
    for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
      cout << "\t" << it->first << it2->first << ", " << it2->second << " class(es)" << endl;
  }
  
  // End/record the time and displaying timing results
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nTime of program execution: " << setprecision(2) << elapsedSeconds << " seconds." << endl << endl;
}