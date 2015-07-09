//
//
//Lab 6b, DvcSchedule Program
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

struct Course
{
  string name; //COMSC
  int count;
};

struct SubjectCode
{
  string name;
  vector<Course> course;
};

int search (vector<SubjectCode>&, string);
int cSearch (SubjectCode&, string);

int main()
{
  cout << "\nLab 6b,DvcSchedule Program \n";
  cout << "Programmer       : Aysin Oruz \n";
  cout << "Editor(s) used   : JNotePad and Xcode \n";
  cout << "Compiler(s) used : Xcode and Terminal \n";
  cout << "Description      : In this lab I will have my first experience with manipulating records from a database by using vector..\n";
  cout << "File             : " <<  __FILE__ << endl;
  cout << "Compiled         : " << __DATE__ << " at " << __TIME__ << endl;
  
  vector<SubjectCode> subjectCodes;
  vector<Course> termSections;
  int numOfLines = 0;
  int caddress = 0;
  int address = 0;
  int duplicates = 0;
  bool noDup;
  SubjectCode miniValue;
  
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
    
    for (int k = 0; k < termSections.size() ; k++)
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
      Course termSection;
      termSection.name = term;
      termSection.count = atoi (section.c_str());
      termSections.push_back(termSection);
    }
    
    //counting the codes
    address = search(subjectCodes, subjectCode);
    Course tempCourse;
    if (address == -1)
    {
      cout << "~";
      numOfLines = 0;
      SubjectCode tempCode;
      tempCode.name = subjectCode;
      tempCourse.name = course;
      tempCourse.count = 1;
      tempCode.course.push_back (tempCourse);
      subjectCodes.push_back(tempCode);
    }
    else
    {
      caddress = cSearch(subjectCodes[address], course);
      if ( caddress == -1)
      {
        tempCourse.name = course;
        tempCourse.count = 1;
        subjectCodes[address].course.push_back(tempCourse);
      }
    }
  }
  
  //sort array
  for(int i = 0; i < subjectCodes.size() ; i++)
  {
    for(int j = i + 1; j < subjectCodes.size(); j++)
    {
      if(subjectCodes[j].name < subjectCodes[i].name)
      {
        SubjectCode temp = subjectCodes[i];
        subjectCodes[i] = subjectCodes[j];
        subjectCodes[j] = temp;
      }
    }
  }
  
  numOfLines++;
  
  for(int i = 0; i < subjectCodes.size(); i++)
  {
    cout << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << subjectCodes[i].name ;
    cout << setw (2) << "," << subjectCodes[i].course.size() << " course(s)\n\n";
    for(int l = 0; l < subjectCodes[i].course.size(); l++)
    {
      cout << "  " << subjectCodes[i].course[l].name;
      cout << " >> " << subjectCodes[i].course[l].count << " Course(s)" << endl << endl;
    }
  }
  
  cout << endl << endl;
  fin.close(); //close file
  // Stop Time
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << duplicates << endl;
  
}


int search (vector<SubjectCode>& sVector, string sName)
{
  for(int index = 0; index < sVector.size(); index++)
  {
    if (sVector[index].name == sName)
    {
      return index;
    }
  }
  return -1;
}

int cSearch (SubjectCode& cVector, string cName)
{
  for (int i = 0; i < cVector.course.size(); i++)
  {
    if (cVector.course[i].name == cName)
    {
      cVector.course[i].count ++;
      return 1;
    }
  }
  return  -1;
}




