// Aysin Oruz
// Xcode, Terminal
//Lab 8b.PreProccesor.cpp

#include <stack>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>
 
struct info
{
  int lineFound;
  char charFound;
};

void errorMsg(char, string, int);
 
int main()
{
  cout << "Lab 8b PreProcessor.cpp" << endl;
  cout << "Aysin Oruz" << endl;
  cout << endl;
 
  stack<info> s;
  info tempInfo;
  
  int lineNumber = 0;
  bool checkError = false;
 
  // for parsing the inputfile
  string fileName;
 
  // open the input file
  ifstream inFile;
 
  //getting the file
  cout << "Enter filename please >> (H, CPP, JAVA, HTML, or JS): \n";
  cin >> fileName;
  inFile.open(fileName.c_str());
  if (!inFile.good()) throw "I/O error";  
 
  cout << "Hello:";

  // read the input file
  while (!inFile.eof())
  {
    string currentLine = "";
    getline(inFile, currentLine);
    lineNumber++;
    cout << "Hello:";

    
    for (int c = 0; c < currentLine.size(); c++)
        {
          cout << "Hello:";
          if (currentLine[c] == '(')
          {
            cout << "Hello:";
            tempInfo.lineFound = lineNumber;
            tempInfo.charFound = currentLine[c];
            s.push(tempInfo);
          }

          if(currentLine[c] == ')')
          {
            if(s.empty())
            {
              errorMsg(currentLine[c], fileName, lineNumber);
              checkError = true;
              break;
            }
            else if(s.top().charFound == ')')
             s.pop();
          }

          if(currentLine[c] == '[')
          {
            tempInfo.lineFound = lineNumber;
            tempInfo.charFound = currentLine[c];
            s.push(tempInfo);
          }

          if(currentLine[c] == ']')
          {
            if(s.empty())
            {
              errorMsg(currentLine[c], fileName, lineNumber);
              checkError = true;
              break;
            }
            else if(s.top().charFound == ']')
              s.pop();
          }

          if(currentLine[c] == '{')
          {
            tempInfo.lineFound = lineNumber;
            tempInfo.charFound = currentLine[c];
            s.push(tempInfo);
          }

          if(currentLine[c] == '}')
          {
            if(s.empty())
            {
              errorMsg(currentLine[c], fileName, lineNumber);
              checkError = true;
              break;
            }
            else if(s.top().charFound == '}')
             s.pop();
          }

          if(currentLine[c] == '/')
          {
            if(currentLine[c+1] == '*')
            {
              tempInfo.lineFound = lineNumber;
              tempInfo.charFound = currentLine[c];
              s.push(tempInfo);
            }
          }
        }
   
    if(checkError == true)
     break;
 }
  
 inFile.close();
}
 
void errorMsg(char c, string filename, int i)
{
  if (c == '(')
  {
      cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching closing parenthesis found." << endl;
  }
 
  if (c == '[')
  {
      cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching closing brackets found." << endl;
  }
 
  if (c == '{')
  {
      cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching closing curly brace found." << endl;
  }
 
  if (c == ')')
  {
          cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching opening parenthesis found." << endl;
  }
 
  if (c == ']')
  {
      cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching opening brackets found." << endl;
  }
 
  if (c == '}')
  {
      cout << c << " found in line " << i << " of " << filename << "." << endl;
      cout << "But no matching opening curly brace found." << endl;
  }
 
 
}