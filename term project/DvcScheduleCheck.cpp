// Term Project - DvcScheduleFinal.cpp
// Programmer: Aysin Oruz
// Editor: Xcode, JNote   Compiler: Xcode, Terminal

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
#include <ctime>

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
  map<string, map<string,int> > outer_map;
  set<string> termSections;
  set<string> subjectCodes;
  map<string,set<string> > invalidM;
  vector<string> invalidV;
  int lines = 0;
  int count = 0;
  
  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  // Start the time!
  clock_t startTime = clock();
  
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
    
    //Search thru file to find invalid entries
    //If not found count ++ and push back the invalids
    if (invalidM.find(term+section) == invalidM.end())
    {
      set<string> subjectCodesE;
      subjectCodesE.insert(subjectCode);
      invalidM[term+section] = subjectCodesE;
    }
    else
    {
      invalidM[term+section].insert(subjectCode);
      if (invalidM[term+section].size() > 1)
      {
        count++;
        invalidV.push_back(section + "     " + subjectCode + "     " + term);
      }  }  }
  
  cout << "\nINVALID ENTRY : " << count << endl;
  cout << "List of Invalid Entries\n";
  cout << "Section  Subject  Term \n";
  cout << "-------  -------  -------\n";
  for(int i = 0; i < count; i++)
    cout << invalidV[i] << endl;
}