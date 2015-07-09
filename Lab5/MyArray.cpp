//
//
//Lab 5a, Array.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>
#include "Array.h"


Array<int> getData();
int calAverage (Array<int> );
int searchArray (Array<int> numbers, int numbers2);

int main()
{
  cout << "\n\nLab 5a,Array.h and MyArray.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description:  The purpose of this lab is for you to ";
  cout << "write a templated class, complete with dynamic memory management.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  Array<int> num1 (2);
  num1 = getData();
  cout << "Here is your array of numbers >> ";
  for (int i = 0; i < num1.length(); i++)
  {
    cout << num1[i] << "  ";
  } cout << endl ;
  
  Array<int> num2 = num1;
  int average = calAverage(num2);
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "\nAverage of your numbers is >>  " << average;
  cout << endl << endl;
  
  int cinNum;
  string buf;
  cout << "Enter a positive number (QUIT = -1) >> " ;
  cin >> buf; cinNum = atoi (buf.c_str());
  cout << endl;
  
  while (cinNum != -1)
  {
    int index = searchArray(num2, cinNum);
    if (index != -1)
      cout << "Found this " << cinNum << " at index " << index << ".\n";
    else
    {
      cout << cinNum <<" is not in this array"<<endl;
    }
    
    cout << "Enter a positive number (QUIT = -1) >> ";
    cin >> buf; cinNum = atoi (buf.c_str());
    cout << endl;
    
  }
}


Array<int> getData()
{
  int i = 0;
  string buf;
  Array<int> num3(2);
  
  cout << "\nEnter a positive number >> ";
  cin >> buf; num3[i] = atoi (buf.c_str());
  cout << endl;
  
  while ( num3[i] != -1)
  {
    i++;
    if (i == num3.length())
      num3.changeSize (i * 2);
    cout << "Enter a positive number (QUIT = -1) >> ";
    cin >> buf; num3[i] = atoi (buf.c_str());
    cout << endl;

  }
  num3.changeSize(i);
  return num3;
}

//calculate the average
int calAverage (Array<int> aveNum)
{
  int sum = 0;
  for ( int i = 0; i < aveNum.length(); i++)
    sum += aveNum[i];
  
  return sum / (aveNum.length());
}


// using lsearch function
int searchArray (Array<int> numbers, int numbers2)
{
  return numbers.lsearch(numbers2);
}
