// Term Project - DvcScheduleFinal.cpp
// Programmer: Aysin Oruz
// Editor: Xcode, JNote
// Compiler: Xcode, Terminal

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>

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
  
  //Open file
  fstream file;
  file.open("dvc-schedule.txt");
  
  //Create map to store subjects and iterator to manipulate it
  map< string, map<string, int> > schedules;
  map< string, map<string, int> >::iterator it;
  map< string,int>::iterator mIt;
  
  //Read, parse and store data
  string subject = "", course = "";
  file.ignore(1000, '\n');
  while(file.good())
  {
    file.ignore(1000, '\t');
    file.ignore(1000, '\t');
    getline(file, subject,'-');
    file>>course; //Input course
    schedules[subject][course]++;
    file.ignore(1000, '\n');
  }
  
  //Formatted output
  cout<<"\n            Subjects List          \n"<<endl;
  for(it = schedules.begin(); it != schedules.end(); it++)
  {
    cout<<"Subject: "<<setw(10)<<left<<it->first; cout<<"  #of Courses: "<<it->second.size()<<endl;
    
    
    for(mIt = it->second.begin(); mIt != it->second.end(); mIt++)
      cout<<"   Course: "<<left<<it->first<<'-'<<setw(8)<<mIt->first<<" #of Classes: "<<mIt->second<<endl;
  }
  

}