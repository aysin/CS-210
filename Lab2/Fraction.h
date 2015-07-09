#ifndef Fraction_h
#define Fraction_h

//#include <iostream>

struct Fraction
{
  int numerator;
  int denominator;

};
  

Fraction operator+ (const Fraction&, const Fraction&);
Fraction operator* (const Fraction&, const Fraction&);
bool operator> (const Fraction&, const Fraction&);
Fraction operator* (const Fraction&, const int x);
Fraction operator* (const int y, const Fraction&);
#endif


