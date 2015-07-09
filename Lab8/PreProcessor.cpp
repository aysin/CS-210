// Aysin Oruz
// Xcode, Terminal
//Lab 8b.PreProccesor.cpp

#include <stack>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>

int main()
{
  cout << "\n\nLab 8b, PreProcessor.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply stack by checking file inputs.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  //will be used for errorchecking
  string fileName; //for input
  string errors;
  string b = ("brackets -[]-");
  string ss = ("slash-star -/* */-");
  string p = ("parenthesis -()-");
  string cB = ("curly brace -{}-");
  stack<char> opens; opens.push('a'); //when stack is empty
  stack<long> lineNumbers; lineNumbers.push(0); //linenumber counter
  char buffer[1000]; //for file name
  char charTemp = '\0'; // temp name holder
  long lineCount = 0; //record the line number
  long lenLine; // Length of the line
  long temp = 0; // keep the file name temp
  bool missedO = true;
  
  cout << "Enter the file name pls (Java, JS, HTML, CPP, or H)\n>> ";
  cin >> fileName;
  ifstream fin; fin.open(fileName.c_str());
  
  //while loop for reading file lines
  while (fin.good() && missedO)
  {
    string lineS;
    getline(fin, lineS);
    strcpy(buffer, lineS.c_str());
    lineCount++;
    lenLine = strlen(buffer);
    
    for(int i = 0; i < lenLine; i++)
    {
      //for openings
      if (buffer[i] == '[' || buffer[i] == '(' || buffer[i] == '{')
      {
        opens.push(buffer[i]); lineNumbers.push(lineCount);
      }
      if (buffer[i] == '/' && buffer[i+1] == '*')
      {
        opens.push(buffer[i]); lineNumbers.push(lineCount);
      }
      
      //for closing
      if (buffer[i] == ']')
      {
        if (opens.top() == '[')
        {
          opens.pop(); lineNumbers.pop();
        }
        else
        {
          missedO = false; errors = b; break;
        }
      }
      if (buffer[i] == ')')
      {
        if (opens.top() == '(')
        {
          opens.pop(); lineNumbers.pop();
        }
        else
        {
          missedO = false; errors = p; break;
        }
      }
      if (buffer[i] == '}')
      {
        if (opens.top() == '{')
        {
          opens.pop(); lineNumbers.pop();
        }
        else
        {
          missedO = false; errors = cB; break;
        }
      }
      if (buffer[i] == '*' && buffer[i + 1] == '/')
      {
        if (opens.top() == '/')
        {
          opens.pop(); lineNumbers.pop();
        }
        else
        {
          missedO = false; errors = ss; break;
        }
      }
      if (!missedO) break;
    }
  }
  
  //Close the inputted file
  fin.close(); cout << endl;
  if (opens.top() != 'a')
  {
    //warn user for missing opennings
    while (opens.top() != 'a')
    {
      temp = lineNumbers.top(); lineNumbers.pop();
      charTemp = opens.top(); opens.pop();
    }
    if ('[' == charTemp) errors = b;
    if ('(' == charTemp) errors = p;
    if ('{' == charTemp) errors = cB;
    if ('/' == charTemp) errors = ss;
    cout << "Opened " << errors << " has been catched on line " << temp << endl;
    cout << "But no matching closing " << errors << " found in " << fileName << endl;
  }
  
  //warn user for missing closings
  else if (opens.top() == 'a' && !missedO)
  {
    if (']' == charTemp) errors = b;
    if (')' == charTemp) errors = p;
    if ('}' == charTemp) errors = cB;
    if ('*' == charTemp) errors = ss;
    cout << "Closed " << errors << " has been catched on line " << temp << endl;
    cout << "But no matching closing " << errors << " found in " << fileName << endl;
  }
  
  //Print out if there is no problem
  else
    cout << "No mismatched has been caugth in " << fileName << endl << endl;
}



