//
//
//Lab 14a, DvcSchedule14b.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <fstream>
#include <iostream>
#include <string>
#include <set>
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
  
  SortableArray<SubjectCode> subjectCodes(1000);
  int count2 = 0;
  int a = 0;
  int numOfLines = 0;
  int dups = 0;
  set<string> duplicates;
  
  
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
    
    //Check if there is duplicates
    string dupCheck = term + section;
    if (duplicates.find(dupCheck) == duplicates.end())
      duplicates.insert(dupCheck);
    else dups++;

    for (int i = 0; i < count2; i++)
    {
      if(subjectCodes[i].name == subjectCode)
      {
        subjectCodes[i].count++;
        a = -1;
        break;
      }
      else continue;
    }
    

    if (a != -1 )
    {
      subjectCodes[count2].name = subjectCode;
      subjectCodes[count2].count = 1;
      count2++;
    }
    else
      a = 0;
    
    numOfLines++;
    if (numOfLines == 1000)
    {
      cout << "~" ;
      numOfLines = 0;
    }
  }
  fin.close();
  cout << endl;
  
  //Sort array
  subjectCodes.sort(count2 - 1);
  for(int i = 0; i < count2; i++)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << subjectCodes[i].name ;
    cout << setw (5) << " >> ";
    cout << subjectCodes[i].count << endl;
  }
  
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << dups << endl;
}
