//
//
//Lab 3c, Fraction.h Fraction.cpp FractionDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include "Fraction.h"

// addition
Fraction Fraction::operator+ (const Fraction& b) const
{
  Fraction newNumber;
  if (denominator == b.denominator)
  {
    newNumber.numerator = numerator + b.numerator;
    newNumber.denominator = denominator;
  }
  else
  {
    newNumber.numerator = (numerator * b.denominator) + (b.numerator * denominator);
    newNumber.denominator = denominator * b.denominator;
  }
  return newNumber;
}

// multiplication
Fraction Fraction::operator* (const Fraction& b) const
{
  Fraction newNumber;
  newNumber.numerator = numerator * b.numerator;
  newNumber.denominator = denominator * b.denominator;
  return newNumber;
}

// comparing if first is bigger than second
bool Fraction::operator>(const Fraction& b) const
{
  bool result = true;
  if(denominator == b.denominator)
  {
    if(b.numerator == numerator)
      result = false;
  }
  else
  {
    Fraction a;
    a.numerator = (numerator * b.denominator) + (b.numerator * denominator);
    a.denominator = denominator * b.denominator;
    
    if(b.numerator > numerator)
      result = false;
  }
  return result;
}

// fraction as first operand and integer as second operand which produce fraction result
Fraction Fraction::operator* (int x) const
{
  Fraction newNumber;
  newNumber.numerator = numerator * (x);
  newNumber.denominator = denominator * (1);
  return newNumber;
}

// integer as first operand and fraction as second operand which produce fraction result
Fraction operator* (int y, const Fraction& a)
{
  Fraction newNumber;
  newNumber.numerator = a.numerator * (y);
  newNumber.denominator = a.denominator * (1);
  return newNumber;
}

