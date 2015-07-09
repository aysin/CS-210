#include <iostream>              // <<, >>, cout, cin
#include <string>                // string, ==, find, npos
#include <cassert>               // assert()
using namespace std;
#include "Stack.h"               // Stack class with StackElement = char

string RPN(string exp);

int main()
{
  string exp;                   // infix expression

  cout << "NOTE:  Enter # for infix expression to stop.\n";
  for (;;)
  {
    cout << "\nInfix Expression?  ";
    getline(cin, exp);
    if (exp == "#") break;
    cout << "RPN Expression is " << RPN(exp) << endl;
  } 
  return 0;
}


/* RPN() converts an infix expression exp to RPN.
 *
 * Receive: Infix expression exp
 * Return:  Corresponding RPN expression
 * Output:  Error message if error found in exp
 ****************************************************************/

string RPN(string exp)
{
  char token,                    // character in exp
       topToken;                 // token on top of opStack
  Stack opStack;                 // stack of operators
  string RPNexp;                 // RPN string
  const string BLANK = " ";      // to insert spaces in RPNexp

  for (int i = 0; i < exp.length(); i++)
  {
    token = exp[i];
    switch(token)
    {
      case ' ' : break;       // do nothing  -- skip blanks

      case '(' : opStack.push(token);
                 break;

      case ')' : for (;;)
                 {
                   assert (!opStack.empty());
                   topToken = opStack.top();
                   opStack.pop();
                   if (topToken == '(') break;

                   RPNexp.append(BLANK + topToken);
                 }
                 break;

      case '+' :  case '-' :
      case '*' :  case '/' :
                 for (;;)
                 {
                   if (opStack.empty() ||
                       opStack.top() == '(' ||
                       (token == '*' || token == '/') &&
                       (opStack.top() == '+' ||  opStack.top() == '-')
                      )
                   {
                     opStack.push(token);
                     break;
                   }
                   else
                   {
                     topToken = opStack.top();
                     opStack.pop();
                     RPNexp.append(BLANK + topToken);
                   }
                 }
                 break;

      default :  RPNexp.append(BLANK + token);
    }
  }

  // Pop remaining operators on the stack
  for (;;)
  {
    if (opStack.empty()) break;

    topToken = opStack.top();
    opStack.pop();
    if (topToken != '(')
    {
      RPNexp.append(BLANK + topToken);
    }
    else
    {
      cout << " *** Error in infix expression ***\n";
      break;
    }
  }
  return RPNexp;
}