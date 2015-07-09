// Aysin Oruz
// Xcode, Terminal
//Lab 8b.PreProccesor.cpp

#include <fstream>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

#include <cstdlib>
#include <cstring>

//pinting the stack function
void printStack(stack<char> );

int main()
{
  //decleare variables
  string fileName;
  ifstream fin;
  int lineCount = 0;
  char chLine;
  stack<char> stackList;
  
  //user input of file name
  cout<<"Enter filename (H, CPP, JAVA, HTML, or JS): ";
  cin >> fileName;
  fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";
  
  //Go thru the file
  while (fin >> chLine)
  {
    
    if( chLine == '\n') // if the line is empty count++
      lineCount++;
    
    // if it finds opening of one of them search for closings
    if (chLine == '(' || chLine == '{' || chLine == '[' )
      stackList.push(chLine);
    
    //Closing Parenthesis Search
    if (chLine==')')
    {
      if (stackList.empty())
      {
        cout << "Opening parenthesis found in line " <<lineCount<< " of " << fileName << endl;
        cout << "But no matching closing parenthesis found\n";
        break;
      }
      
      char openCh = stackList.top(); stackList.pop();
      if (openCh != '(')
      {
        cout << "Closing parenthesis found in line " << lineCount << " of " << fileName << endl;
        cout << "But no matching opening parenthesis found\n";
        break;
      }
    }
    
    //Closing Square Bracets Search
    if (chLine == ']')
    {
      if (stackList.empty())
      {
        cout << "Opening parenthesis found in line " << lineCount << " of " << fileName << endl;
        cout << "But no matching closing parenthesis found\n";
        break;
      }
      
      char openCh = stackList.top(); stackList.pop();
      if (openCh != '[')
      {
        cout << "Closing parenthesis found in line " << lineCount << " of " << fileName << endl;
        cout << "But no matching opening parenthesis found";
        break;
      }
    }
    
    //closing curly bracelets search
    if (chLine == '}')
    {
      if (stackList.empty())
      {
        cout << "Opening parenthesis found in line " << lineCount << " of " << fileName << endl;
        cout << "But no matching closing parenthesis found";
        break;
      }
      
      char openCh = stackList.top(); stackList.pop();
      if (openCh != '{')
      {
        cout << "Closing parenthesis found in line " << lineCount << " of " << fileName << endl;
        cout << "But no matching opening parenthesis found\n";
        break;
      }
    }
    //if list has no mismatch print it
    if (stackList.empty())
    {
      cout << "No mismatches found by preprocessor in " << fileName << endl;
      break;
    }
  }
}

void printStack(stack<char> sList)
{
  stack<char> tempStack = sList;
  cout<<"current stack:"<<endl;
  while (!tempStack.empty())
  {
    char s = tempStack.top(); tempStack.pop();
    cout << s << " ";
  }
  cout<<"\n\n";
}
