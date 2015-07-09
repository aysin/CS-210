#include "Fraction.h"
#include "Fraction.h"

#include <iostream>
using namespace std;

int main()
{
  cout << "\n\nLab 2a,Fraction.h, Fraction.cpp FractionDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this Lab to understand and work with oveloaded operators.";
  cout << "The program by itself adds, multiply and compares two fraction number or one fraction one integer number. \n\n";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  //decleare variables
	Fraction a;
  Fraction b;
  Fraction f;
  
  //initlize numbers to variables
  a.numerator = 1;
  a.denominator = 2;
  b.numerator = 1;
  b.denominator = 4;
  
  //Print out what the numbers I will use
  cout << "\nFraction numbers will be; a = 1/2, b = 1/4 \n";
  
  // Testing overloaded + operator with two Fraction parameters.
  f = a + b;
  cout << "\nTesting + operator with two fraction\n";
  cout << "Expected number: 6/8 \n";
  cout << "Actual result: " << f.numerator << '/' << f.denominator << endl;
  
  // Testing overloaded * operator with two Fraction parameters.
  f = a * b;
  cout << "\nTesting * operator with two fraction.\n";
  cout << "Expected number: 1/8 \n";
  cout << "Actual result: " << f.numerator << '/' << f.denominator << endl;
  
  // Testing overloaded > operator with two Fraction parameters.
  cout << "\nTesting > operator with two fraction\n";
  cout << "Expected result: 1/2 is graeter than 1/4\n";

  if(a > b)
  {
    cout << "Actual result: " << a.numerator << '/' << a.denominator
    << " is greater than " << b.numerator << '/' << b.denominator << endl;
  }
  else
  {
    cout << "Actual result: " <<a.numerator << '/' << a.denominator
    << " is not greater than " << b.numerator << '/' << b.denominator << endl;
  }

  // Testing overloaded * operator with integer/fraction
  f = 7 * a;
  cout << "\nTesting * operator with integer/fraction\n";
  cout << "Expected number: 7/2 \n";
  cout << "Actual result: " << f.numerator << '/' << f.denominator << endl;
  
  // Testing overloaded * operator with fraction/integer
  f = a * 2;
  cout << "\nTesting * operator with fraction/integer\n";
  cout << "Expected number: 2/2  \n";
  cout << "Actual result: " << f.numerator << '/' << f.denominator << endl;
  
  // Object copy testing, with assignment UPON declaration, to observe that the copy is equal to the original.
  {
    Fraction copy = a;
    
    cout << "\nTest for object copying, with assignment UPON declaration." << endl;
    cout << "Expected number: 1/2" << endl;
    cout << "Actual result: " << copy.numerator << '/' << copy.denominator << endl << endl;
  }
  
  // Object copy testing, with assignment AFTER declaration, to observe that the copy is equal to the original.
  {
    Fraction copy; copy = b;
    
    cout << "Test for object copying, with assignment AFTER declaration." << endl;
    cout << "Expected number: 1/4" << endl ;
    cout << "Actual result: " << copy.numerator << '/' << copy.denominator << endl << endl;
  }
  
}
