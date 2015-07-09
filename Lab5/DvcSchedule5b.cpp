//
//
//Lab 5b, DvcSchedule Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <ctime>
#include <cstring>
#include "Array.h"


struct SubjectCode
{
  string name;
  int count;
};


int main()
{
  cout << "\nLab 5b,DvcSchedule Program \n";
  cout << "Programmer       : Aysin Oruz \n";
  cout << "Editor(s) used   : JNotePad and Xcode \n";
  cout << "Compiler(s) used : Xcode and Terminal \n";
  cout << "Description      : In this lab I will have my first experience with manipulating records from a database..\n";
  cout << "File             : " <<  __FILE__ << endl;
  cout << "Compiled         : " << __DATE__ << " at " << __TIME__ << endl;
  
  Array<SubjectCode> subCodeArr(1000);
  Array<string> currentTerm(60000);
  Array<string> currentSection(60000);
  
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
  
  // Start Time
  clock_t startTime = clock();
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // Rad txt file
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
    
    //duplicates the same entry
    if(noDup)
    {
      noArr = true;
      
      for(int i = 0; i < subCodeArrSize; i++)
      {
        if(subCodeArr[i].name == subjectCode)
        {
          noArr = false;
          subCodeArr[i].count++;
          break;
        }
      }
      
      if(noArr)
      {
        subCodeArr[subCodeArrSize].name = subjectCode;
        subCodeArr[subCodeArrSize].count = 1;
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
  
  cout << endl << endl;
  fin.close(); //close file
  
  //sort array
  for(int i = 0; i < subCodeArrSize; i++)
  {
    int k = i;
    
    for(int j = i + 1; j < subCodeArrSize; j++)
    {
      if(subCodeArr[k].name > subCodeArr[j].name)
        k = j;
    }
    
    SubjectCode temp = subCodeArr[i];
    subCodeArr[i] = subCodeArr[k];
    subCodeArr[k] = temp;
  }
  
  for(int i = 0; i < subCodeArrSize; i++)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << subCodeArr[i].name ;
    cout << setw (5) << " >> ";
    cout << subCodeArr[i].count << endl;
  }
  
  // Stop Time
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << duplicates << endl;
  
  
  
}