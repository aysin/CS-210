#include "Fraction.h"


// addition
Fraction operator+ (const Fraction& a, const Fraction& b)
{
  Fraction newNumber;
  newNumber.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
  newNumber.denominator = a.denominator * b.denominator;
  return newNumber;
}

// multiplication
Fraction operator* (const Fraction& a, const Fraction& b)
{
  Fraction newNumber;
  newNumber.numerator = a.numerator * b.numerator;
  newNumber.denominator = a.denominator * b.denominator;
  return newNumber;
}

// comparing if first is bigger than second
bool operator> (const Fraction& a, const Fraction& b)
{
  if(a.numerator > b.numerator)
    return false;
    return true;
}

// fraction as first operand and integer as second operand which produce fraction result
Fraction operator* (const Fraction& a, const int x)
{
  Fraction newNumber;
  newNumber.numerator = a.numerator * (x);
  newNumber.denominator = a.denominator * (1);
  return newNumber;
}

// integer as first operand and fraction as second operand which produce fraction result
Fraction operator* (const int y, const Fraction& a)
{
  Fraction newNumber;
  newNumber.numerator = a.numerator * (y);
  newNumber.denominator = a.denominator * (1);
  return newNumber;
}