//
//
//Lab 7a, DvcSchedule Program
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

// the linked-list node
struct Node
{
  SubjectCode data;
  Node* next;
};

void print(Node &); //Function to print the subject structures in the deque


int main()
{
  cout << "\nLab 7a,DvcSchedule Program \n";
  cout << "Programmer       : Aysin Oruz \n";
  cout << "Editor(s) used   : JNotePad and Xcode \n";
  cout << "Compiler(s) used : Xcode and Terminal \n";
  cout << "Description      : In this lab I will have my first experience with manipulating records from a database by using linked List..\n";
  cout << "File             : " <<  __FILE__ << endl;
  cout << "Compiled         : " << __DATE__ << " at " << __TIME__ << endl;
  
  
  Node subjectCodes;
  vector<SubjectCode> termSections;
  Node* p;
  Node* q;
  Node* start = 0 ;
  
  
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
    
    //Find duplicates
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
      string tempSCode = subjectCode;
      for(p = start; p; p = p->next)
      {
        if (tempSCode.compare(p->data.name)==0)
        {
          p->data.count++;
          tempSCode = "0";
          break;
        }
      }
      
      //adding a node
      if (tempSCode != "0" )
      {
        Node *node = new Node;
        node->data.name = subjectCode;
        node->data.count = 1;
        node->next = start;
        start = node;
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
  
  
  //Sort the list
  for (p = start; p; p = p->next)
  {
    for (q = p->next; q; q = q->next)
    {
      if (p->data.name.compare(q->data.name) > 0)
      {
        SubjectCode temp = p->data;
        p->data = q->data;
        q->data = temp;
      } } }
  
  // Print the list
  for(p = start; p; p = p->next)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw (5) << p->data.name ;
    cout << setw (5) << " >> ";
    cout << p->data.count << endl;
  }
  
  //Deallocation
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
  
  // Stop Time
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "\nRunning time is >> " << elapsedSeconds << " seconds" << endl;
  cout << "Duplicates      >> " << duplicates << endl;
  
}
