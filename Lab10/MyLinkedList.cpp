 //
//
//Lab 10b MyLinkedList.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>
#include "LinkedList.h"


LinkedList<int> getData();
int calAverage (LinkedList<int> );

int main()
{
  cout << "\n\nLab 10b, MyLinkedList.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description:  The purpose of this lab is for you to ";
  cout << "write a templated class, complete with linkedlist management.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  LinkedList<int> num1;
  num1 = getData();
  int a;
  cout << "\nList >> ";
  num1.first(a); cout << a << " ";
  for (int i = 1; i < num1.length(); i++)
  {
    cout << num1[i] << " ";
  } cout << endl ;
  
  LinkedList<int> num2 = num1;
  int average = calAverage(num2);
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "Average of your numbers is >>  " << average;
  cout << endl << endl;
  
  while (true)
  {
    int cinNum;
    string buf;
    
    cout << "Enter a positive number (QUIT = -1) >> " ;
    cin >> buf; cinNum = atoi (buf.c_str());
    cout << endl;
    
    if (cinNum == -1)
      break;
    
    if (num1.find(cinNum))
      cout << "Found this " << cinNum << " at index " << num1.currentIndex << ".\n";
    else
      cout << cinNum <<" is not in this list"<<endl;
  }
  
}


LinkedList<int> getData()
{
  int i = 0;
  string buf;
  LinkedList<int> num3;
  
  cout << "\nEnter a positive number >> ";
  cin >> buf; i = atoi (buf.c_str());
  
  while ( i != -1)
  {
    num3.insert(i);
    cout << "Enter a positive number (QUIT = -1) >> ";
    cin >> buf; i = atoi (buf.c_str());
  }
  return num3;
}



//calculate the average
int calAverage (LinkedList<int> aveNum)
{
  int sum = 0;
  for ( int i = 0; i < aveNum.length(); i++)
    sum += aveNum[i];
  
  return sum / (aveNum.length());
}

