//
//
//Lab 3c, Fraction.h Fraction.cpp FractionDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  int numerator;
  int denominator;
  
  Fraction operator+ (const Fraction&) const;
  Fraction operator* (const Fraction&) const;
  Fraction operator* (int x) const;
  bool operator> (const Fraction&) const;

};

//Stand alone operator
Fraction operator* (int y, const Fraction&);


#endif


