//Cory Jbara - Lab 2
//Implementation for Rational class

#include "Rational.h"
#include <iostream>

//Constructor sets numerator and denominator to 1 or whatever values specified by function call
Rational::Rational(int n, int d){
  numerator=n;
  if(d!=0)  denominator=d;	//cannot set denominator to 0, defaults to 1 instead
  else{
	denominator=1;
	cout << "The denominator cannot be 0, it has been set to 1." << endl;
  }

  simplify();	//simplify all stored values
}

//This overload displays the rational in its reduced form
ostream& operator<<(ostream &output, Rational &R){
  //if the denominator is 1, only display numerator
  if(R.denominator==1){
	output << " " << R.numerator << " ";
  } else {
  	output << " " << R.numerator << "/" << R.denominator << " ";
  }
  return output;
}

//Simplifies a Rational fraction (member function called inside of an operator)
void Rational::simplify(){
  int gcd=this->getgcd();	//gets gcd
  //simplify rational by dividing both numerator and denominator by gcd
  if(gcd!=0){
    numerator/=gcd;		
    denominator/=gcd;
  }
}  

//This function returns the GCD of the numerator and denominator of a Rational (only to be used internally)
int Rational::getgcd(){
  int temp;
  int a=numerator;
  if(a==0) return 0;
  int b=denominator;
  if(b>a){
    temp=b; //x is a placeholder to make sure a is bigger than b
    b=a;
    a=temp;
  }

  int c=a%b;
//this is using euclidian algorithm
  while(c!=0){
    int x = b % c; //x is again used as a placeholder for the value needed to be stored in c
    b=c;
    c=x;
  }

//after loop breaks, b is the gcd
  return b;
}

int Rational::getN(){	return numerator;	}
int Rational::getD(){	return denominator;	}

//Addition operator
Rational& Rational::operator+(Rational &R1){
  int commonD;	//this is the two denominators multiplied together, will be stored into new rational
  //After finding the added sum, simplify to base form
  commonD = R1.getD() * denominator;
  
  int newN;	//numerator to be stored into the new Rational
  newN = (numerator * R1.getD()) + (R1.getN() * denominator);
  
  //create new rational with newN and commonD
  Rational *R3;
  R3= new Rational(newN,commonD);
  return *R3;
}

//Subtraction operator
Rational& Rational::operator-(Rational &R1){
  int commonD;	//this is the two denominators multiplied together, will be stored into new rational
  //After finding the added sum, simplify to base form
  commonD = R1.getD() * denominator;
  
  int newN;	//numerator to be stored into the new Rational
  newN = (numerator * R1.getD()) - (R1.getN() * denominator);
  
  //create new rational with newN and commonD
  Rational *R3;
  R3= new Rational(newN,commonD);
  return *R3;
}

//Multiplication operator
Rational& Rational::operator*(Rational &R1){
  int commonD;	//this is the two denominators multiplied together, will be stored into new rational
  commonD = R1.getD() * denominator;
  
  int commonN;	//numerator, two numerators multiplied together
  commonN = R1.getN() * numerator;
  
  //create new rational with newN and commonD
  Rational *R3;
  R3= new Rational(commonN,commonD);
  return *R3;
}

//Divide operator
Rational& Rational::operator/(Rational &R1){
  int newD;	//this is the two denominators multiplied together, will be stored into new rational
  newD = R1.getN() * denominator;
  if(newD==0){	
	cout << "You cannot divide by 0, the divide function will not work here." << endl;
	cout << "We will change the numerator to 1 instead." << endl;
  }//does not let the divide by 0 
 
  int newN;	//numerator, two numerators multiplied together
  newN = R1.getD() * numerator;
  
  //create new rational with newN and commonD
  Rational *R3;
  R3= new Rational(newN,newD);
  return *R3;
}

//exponent operator
Rational& Rational::operator^(int exponent){
  int n,d;//n gets multiplied by itself exponent times, and same with d
  n=numerator;
  d=denominator;

  for(int i=1; i<exponent; i++){//loop to create the powers
    n*=numerator;
    d*=denominator;
  }

  Rational *R;
  R= new Rational(n,d);	//create a new rational to return
  return *R;
}
















