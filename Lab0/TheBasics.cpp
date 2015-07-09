//
//
//Lab 0c, The Basics Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>

int main()
{
  //print my name and this assignments title
  cout << "\n\nLab 0c, The Basics Program \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: TheBasics.cpp, to read and print two sets of inputs, with two calculated values.";
  cout << "It calculates the user current age and next year age also converts temprature from F to C.\n";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  string buf, name, city;
  int age, age2;
  float ftemp, ctemp;
    
  // Ask user to enter age, name, temprerature, and city  
  cout << "\nWhat is your age? \n";
  cin >> buf; age = atoi (buf.c_str());
  cin.ignore (1000, 10);
  cout << "\nWhat is your name? \n";
  getline (cin, name);
  cout << "\nWhat is the outside temprature in F: \n";
  cin >> buf; ftemp = atof (buf.c_str());
  cin.ignore (1000, 10);
  cout << "\nEnter the city you are in: \n";
  getline (cin, city);
    
  //converts F to C
  ctemp=(ftemp-32)*5.0/9.0;
    
  //calculate age for next year
  age2 = age + 1;
  
  cout << endl;
  cout << name << " is " << age << " now, and will be " << age2 <<" a year from now.\n"
  << "Its " << ftemp << "F in " << city << endl;
  cout.setf (ios::fixed|ios::showpoint);
  cout << "That's " << setprecision(1) << ctemp << " degrees C\n\n\n";
    

}