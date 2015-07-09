//
//
//Lab 11a, HashTable.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include <cassert>
#include <cstring>

#include "HashTable.h"
#include "HashTable.h" //ifndef testing

struct Course
{
  string term;
  string section;
  string course;
  string instructor;
  
  //hashCode function
  int hashCode() const
  {
    int h = 0;
    for (int i = 0; i < term.size(); i++)
      h = h + term[i];
    for (int i = 0; i < section.size(); i++)
      h = h + term[i];
    for (int i = 0; i < course.size(); i++)
      h = h + term[i];
    for (int i = 0; i < instructor.size(); i++)
      h = h + term[i];
    return h;
  }
  //Creating == as member
  bool operator==(const Course& a) const
  {
    return term == a.term && section == a.section;
  }
};


int main ()
{
  
  cout << "\n\nLab 11a, HashTableDriver.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply our HashCode.h file.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  HashTable <Course, 1009> recs;
  Course list;
  int lineCount = 0;
  int dups = 0;
  
  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  // opening the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  
  if(!fin.good())
    throw "I/O error";
  
  // reading the input file and store the recs
  while(fin.good())
  {
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0)
      continue;
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos)
      continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    //break at 100th line
    if (lineCount == 101) break;
    
    list.term = term;
    list.section = section;
    list.course = course;
    list.instructor = instructor;
    recs.insert(list);
    lineCount++;
  }
  
  //close the file
  fin.close();
  
  //testing insertion function
  cout << "\n\nTesting insertion function\n";
  cout << "Expected >> 100\n";
  cout << "Actual >> " << recs.size() << endl;
  
  //set lineCount to 0
  lineCount = 0;
  
  // opening the input file
  fin.open("dvc-schedule.txt");
  
  if(!fin.good())
    throw "I/O error";
  
  // reading the input file and store the recs
  while(fin.good())
  {
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0)
      continue;
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos)
      continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    //break at 100th line
    if (lineCount == 101) break;
    if (recs.retrieve(list) == 0) continue;
    else
    {
      recs.remove(list);
      assert(recs.remove(list) == 0);
      dups++;
    }
    
    lineCount++;
  }
  
  //closing file
  fin.close();
  
  //testing insertion function
  //Dupilcates and Size
  cout << "\nInsert and size testing with Duplicates\n";
  cout << "Capacity >> " << recs.size() << endl;
  cout << "Duplicates >> " << dups << endl;
 
  
  // Const object copy testing with assignment UPON declaration
  {
    const HashTable<Course, 1009> copy = recs;
    cout << "\nConst object copy testing with assignment UPON declaration\n";
    
    //testing insertion function
    cout << "\nTesting insertion function\n";
    cout << "Expected >> 99\n";
    cout << "Actual >> " << copy.size() << endl;
    assert (recs.size() == copy.size());
  }
  
  // Const object copy testing with assignment AFTER declaration
  {
    HashTable<Course, 1009> copy; copy = recs;
    cout << "\nConst object copy testing with assignment AFTER declaration\n";
    Course a;
    
    //Testing insert function by adding
    copy.insert(a);
    copy.replace(a);
    copy.retrieve(a);
    assert(copy.retrieve(a));
    copy.remove(a);
    assert(copy.remove(a) == 0);
    copy.clear();
    cout << "All functions passed the test\n";
  }
  
  
  //Testing to Clear Func
  cout << "\nTesting clear()\n";
  cout << "Expected >> List is clean now\n";
  recs.clear();
  cout << "Actual >> List is clean now\n";
  
  
}