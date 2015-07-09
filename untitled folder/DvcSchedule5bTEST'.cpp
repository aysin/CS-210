//
//
//Lab 14a, DvcSchedule14b.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include <cstring>
#include <ctime>
#include <iomanip>
#include "SortableArray.h"

struct SubjectCode
{
  string name;
  int count;
  
  bool operator<(const SubjectCode& c) const {return name < c.name; }
};


int main()
{
  cout << "\nLab 14b,DvcSchedule Program \n";
  cout << "Programmer       : Aysin Oruz \n";
  cout << "Editor(s) used   : JNotePad and Xcode \n";
  cout << "Compiler(s) used : Xcode and Terminal \n";
  cout << "Description      : In this lab I will have my first experience with manipulating records from a database..\n";
  cout << "File             : " <<  __FILE__ << endl;
  cout << "Compiled         : " << __DATE__ << " at " << __TIME__ << endl;
  
  SortableArray<SubjectCode> subjectCodes(100);
  SortableArray<string> currentTerm(60000);
  SortableArray<string> currentSection(60000);
  int subCodeArrSize = 0;
  int currentTSsize = 0;
  int numOfLines = 0;
  int duplicates = 0;
  bool noDup;
  bool noArr;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  clock_t startTime = clock();
  
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
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
    
    noDup = true;
    
    for(int i = 0; i < currentTSsize; i++)
    {
      if(currentTerm[i] == term && currentSection[i] == section)
      {
        noDup = false;
        duplicates++;
        break;
      }
    }
    
    if(noDup)
    {
      currentTerm[currentTSsize] = term;
      currentSection[currentTSsize] = section;
      currentTSsize++;
    }
    
    if(noDup)
    {
      noArr = true;
      
      for(int i = 0; i < subCodeArrSize; i++)
      {
        if(subjectCodes[i].name == subjectCode)
        {
          noArr = false;
          subjectCodes[i].count++;
          break;
        }
      }
      
      if(noArr)
      {
        subjectCodes[subCodeArrSize].name = subjectCode;
        subjectCodes[subCodeArrSize].count = 1;
        subCodeArrSize++;
      }
    }
    
    numOfLines++;
    if (numOfLines == 1000)
    {
      cout << "~" ;
      numOfLines = 0;
    }
  }
  fin.close();
  
  //Sort array
  
  subjectCodes.sort(subCodeArrSize - 1);
  for(int i = 0; i < subjectCodes; i++)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << subjectCodes[i].name ;
    cout << setw (5) << " >> ";
    cout << subjectCodes[i].count << endl;
  }
  
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << duplicates << endl;
}
