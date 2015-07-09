// Term Project - DvcScheduleFinal.cpp
// Programmer: Aysin Oruz
// Editor: Xcode, JNote   Compiler: Xcode, Terminal

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main()
{
  cout << "\n\nTerm Project -  DvcScheduleFinal.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: Term Project - DvcScheduleFinal.cpp file.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  //create variables
  map<string, map<string,int> > maps;
  map<string, map<string,int> >::iterator it;
  int lines = 0, count = 0;
  
  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  // Open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
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
   
    it = (maps.begin(), maps.end(), it++);
    if (it != maps.end())
    {
      if (it->second == maps[section, subjectCode])
        continue;
      else
      {
        for(it = maps.begin(); it != maps.end(); ++it)
          cout << it->first << "  ";
      }
    }
    
  }
  
 
}