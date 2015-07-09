#include <iostream>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "Stack.h"
 
using namespace std;
 
int main()
{
  
        //variable declarations
        Stack<float> a;
        string input;
        float num1, num2, result;
        char choice;
       
        while (true)
        {
          cout << "Enter: ";
          cin >> input;
          if (input == "Q" || input == "q")
                break;
          else if (input == "+" || input == "-" || input == "/" || input == "*")
          {
                num2 = a.peek();
                a.pop();
                num1 = a.peek();
                a.pop();
                choice = input[0];
                cout << setprecision(5);
                switch(choice)
                {
                  case '+':
                    result = num1 + num2;
                    a.push(result);
                    cout << "result: " << result << endl;
                    break;
                  case '-':
                    result = num1 - num2;
                    a.push(result);
                    cout << "result: " << result << endl;
                    break;
                  case '*':
                    result = num1 * num2;
                    a.push(result);
                    cout << "result: " << result << endl;
                    break;
                  case '/':
                    result = num1 / num2;
                    a.push(result);
                    cout << "result: " << result << endl;
                    break;
                }
        }
        else
          a.push(atof(input.c_str()));
  }
  return 0;
}