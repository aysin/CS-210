//
//
//Lab 8a, Calculator2.cpp Program
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
  cout << "\n\nLab 8a Calculator8\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab to learn how to apply the stack.h";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "\n\nWelcome to the RPN Calculator\n";
  cout << "Press Q to exit anytime!\n";
  
  Stack<double> rpnStack;
  string buffer;
  double number;
  double i;
  int size = 0;
  
  // Prompt user
  cout << "\nEnter >> ";
  cin >> buffer;
  
  while (true)
  {
    // Invalid if user enters one of the orernt first
    while((buffer[0] == '+' && size < 2) || (buffer[0] == '-' && size < 2)
       ||(buffer[0] == '*' && size < 2) ||(buffer[0] == '/' && size < 2))
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
      first = rpnStack.peek(first); rpnStack.pop(first);
      second = rpnStack.peek(second); rpnStack.pop(second);
      third = first * second;
      rpnStack.push (third);
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres / sign
    else if ( buffer[0] == '/')
    {
      double first, second, third;
      first = rpnStack.peek(first); rpnStack.pop(first);
      second = rpnStack.peek(second); rpnStack.pop(second);
      third = second / first;
      rpnStack.push (third);
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres + sign
    else if ( buffer[0] == '+')
    {
      double first = 0, second = 0, third = 0;
      first = rpnStack.peek(first); rpnStack.pop(first);
      second = rpnStack.peek(second); rpnStack.pop(second);
      third = first + second;
      rpnStack.push (third);
      
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
    }
    
    //if the user enteres - sign
    else if ( buffer[0] == '-')
    {
      double first, second, third;
      first = rpnStack.peek(first); rpnStack.pop(first);
      second = rpnStack.peek(second); rpnStack.pop(second);
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
      size++;
    }
    
    // First in, push to end
    cout <<  "Enter >> " ;
    for(Stack<double> copy = rpnStack; !copy.isEmpty(); copy.pop(i))
    {
      copy.peek(i);
      cout << i << " ";
    }
    cin >> buffer;
  }
}








