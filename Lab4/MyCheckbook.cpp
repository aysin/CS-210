//
//
//Lab 4b, CheckBook Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <cstdlib>
#include "Checkbook.h"
#include "Checkbook.h"  // ifndef testing

int main ()
{
  cout << "\n\nLab 4b,MyCheckBook.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: In this lab I will learn how to apply array size doubling..";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  //variable decleration
  float amount;
  float balance;
  float *checkPointer;
  int number;
  int list;
  string buf;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout << "\nPlease enter the initial balance:  ";
  cin >> buf; balance = atof (buf.c_str());
  cout << "\nCURRENT BALANCE >> $ " << balance << endl;
  
  Checkbook<float> cbook(balance);
  
  while (true)
  {
    cout << "SERVICES";
    cout << "\n1) Write a check" << endl;
    cout << "2) Make a deposit" << endl;
    cout << "3) Get the balance" << endl;
    cout << "4) Print a list of written checks" << endl;
    cout << "5) Quit" << endl;
    
    cout << "\nPlease choose a number to complete your service: \n";
    cin >> buf; number = atoi (buf.c_str());
    
    if ( number != 1 && number != 2 && number != 3 && number != 4 && number != 5)
    {
      cout << "INVALID ENTRY! TRY AGAIN PLEASE!\n\n";
      cout << "SERVICES";
      cout << "\n1) Write a check" << endl;
      cout << "2) Make a deposit" << endl;
      cout << "3) Get the balance" << endl;
      cout << "4) Print a list of written checks" << endl;
      cout << "5) Quit" << endl;
      cout << "\nPlease choose a number to complete your service: \n";
      cin >> buf; number = atoi (buf.c_str());
    }

    switch (number)
    {
      case 1:
        cout << "Enter check amount please:  \n";
        cin >> buf; amount = atof (buf.c_str());
        if ( cbook.writeCheck(amount))
          cout << "Thank you for entry. Approved!\n\n";
        else
          cout << "Amount is bigger than your budget! Disapproved!\n\n";
        break;
      case 2:
        cout << "Enter deposit amount please: \n";
        cin >> buf; amount = atof (buf.c_str());
        cbook.deposit(amount);
        cout << "Thank you for entry. Approved!\n\n";
        break;
      case 3:
        amount = cbook.getBalance();
        cout << "CURRENT BALANCE >> $ " << amount << endl << endl;
        break;
      case 4:
        list = cbook.getLastIndex();
        checkPointer = cbook.getChecks();
        cout << "LIST OF WRITTEN CHECKS\n";
        cout << "----------------------\n";
        for (int i = 0; i < list; i++)
          cout << "$" << checkPointer[i] << endl << endl;
        break;
      default:
        break;
    }
    if ( number == 5)
      break;
  }
}