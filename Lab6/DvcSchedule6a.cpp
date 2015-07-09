//
//
//Lab 6a, DvcSchedule Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include <ctime>
#include <cstring>


struct SubjectCode
{
  string name;
  int count;
};


int main()
{
  cout << "\nLab 6a,DvcSchedule Program \n";
  cout << "Programmer       : Aysin Oruz \n";
  cout << "Editor(s) used   : JNotePad and Xcode \n";
  cout << "Compiler(s) used : Xcode and Terminal \n";
  cout << "Description      : In this lab I will have my first experience with manipulating records from a database by using vector..\n";
  cout << "File             : " <<  __FILE__ << endl;
  cout << "Compiled         : " << __DATE__ << " at " << __TIME__ << endl;
  
  vector<SubjectCode> subjectCodes;
  vector<SubjectCode> termSections;
  int numOfLines = 0;
  int duplicates = 0;
  bool noDup;
  
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
    
    noDup = false;
    
    for (int k = 0; k < termSections.size(); k++)
    {
      if (termSections[k].name == term && termSections[k].count == atof(section.c_str()))
      {
        duplicates++;
        noDup = true;
        break;
      }
    }
    if (!noDup)
    {
      SubjectCode termSection;
      termSection.name = term;
      termSection.count = atoi (section.c_str());
      termSections.push_back(termSection);
      
      bool notFound = false;
      for (int i = 0; i < subjectCodes.size(); i++)
      {
        if (subjectCodes[i].name == subjectCode)
        {
          notFound = true;
          subjectCodes[i].count++;
          numOfLines = -1;
          break;
        }
      }
      //if no duplicates found
      if (numOfLines != -1)
      {
        cout << '~';
        numOfLines = 0;
        SubjectCode sc;
        sc.count = 1;
        sc.name = subjectCode;
        subjectCodes.push_back(sc);
      }
    }
    
    numOfLines++;
  }
  
  cout << endl << endl;
  fin.close(); //close file
  
  //sort array
  for(int i = 0; i < subjectCodes.size(); i++)
  {
    for(int j = i + 1; j < subjectCodes.size(); j++)
    {
      if(subjectCodes[i].name > subjectCodes[j].name)
      {
        SubjectCode temp = subjectCodes[i];
        subjectCodes[i] = subjectCodes[j];
        subjectCodes[j] = temp;
      }
    }
  }
  
  for(int i = 0; i < subjectCodes.size(); i++)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << subjectCodes[i].name ;
    cout << setw (5) << " >> ";
    cout << subjectCodes[i].count << endl;
  }
  
  // Stop Time
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << duplicates << endl;
  
  
}