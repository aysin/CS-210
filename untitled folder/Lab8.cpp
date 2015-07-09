//
//
//Lab 2c, Calculator2.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Stack.h"
#include <cstdlib>

int main()
{
  cout << "\n\nLab 2c Calculator2\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab to learn how to apply the STL stack";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "\n\nWelcome to the RPN Calculator\n";
  cout << "Press Q to exit anytime!\n";
  
  Stack<double> rpnStack;
  string buffer;
  double number;
  
  double 
  
  
  // Prompt user
  cout << "\nEnter >> ";
  cin >> buffer;
  
  while (true)
  {
    // Invalid if user enters one of the orernt first
    for(Stack<double> copy = rpnStack; !copy.isEmpty(); copy.pop())
    {
      // Prompts user to enter again
      cout << "\nInvalid Entry .. Try Again!\nEnter >> ";
      cin >> buffer;
    }
    
    // check for quit
    if ( buffer == "Q" || buffer == "q") break;
    
    //Check for operants
    //if the user enteres * sign
    if ( buffer[0] == '*')
    {
      double first, second, third;
      first = rpnStack.peek(); rpnStack.pop();
      second = rpnStack.peek(); rpnStack.pop();
      third = first * second;
      rpnStack.push (third);
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres / sign
    else if ( buffer[0] == '/')
    {
      double first, second, third;
      first = rpnStack.peek(); rpnStack.pop();
      second = rpnStack.peek(); rpnStack.pop();
      third = second / first;
      rpnStack.push (third);
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres + sign
    else if ( buffer[0] == '+')
    {
      double first, second, third;
      first = rpnStack.peek(); rpnStack.pop();
      second = rpnStack.peek(); rpnStack.pop();
      third = first + second;
      rpnStack.push (third);
      
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres - sign
    else if ( buffer[0] == '-')
    {
      double first, second, third;
      first = rpnStack.peek(); rpnStack.pop();
      second = rpnStack.peek(); rpnStack.pop();
      third = second - first;
      rpnStack.push (third);
      
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    else
    {
      number = atof (buffer.c_str());
      cin.ignore (1000,10);
      rpnStack.push(number);
    }
    
    // First in, push to end
    cout <<  "Entered << " ;
    for(Stack<double> copy = rpnStack; !copy.empty(); copy.pop())
      cout <<  copy.peek() << " ";
    cin >> buffer;
  }
}








