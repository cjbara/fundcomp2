//Cory Jbara - Lab 2
//Interface for the Rational class
#include <iostream>
#ifndef RATIONAL_H
#define RATIONAL_H
using namespace std;

class Rational{
  friend ostream &operator<<( ostream &, Rational &);

  public:
    Rational(int=1, int=1);
    int getN();	//returns numerator
    int getD(); //returns denominator
    Rational& operator+(Rational &);//Adds two rationals
    Rational& operator-(Rational &);//Subtracts two rationals
    Rational& operator*(Rational &);//Multiplies two rationals
    Rational& operator/(Rational &);//Divides two rationals
    Rational& operator^(int);	    //Exponent function with int as the power

  private:
    int numerator;		//numerator of Rational
    int denominator;		//denominator of Rational
    int getgcd();		//Returns GCD of numerator and denominator
    void simplify();		//Simplifies a rational using GCD

};

#endif
