#include "Rational.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  int n,d,power;
  //this begins interactive mode
  system("clear");	//clears the screen

  cout << "We will create two rationals, which the program will play with." << endl;
  cout << "Please enter a numerator and denominator." << endl << "Numerator: ";
  cin >> n;	//stores numerator into n
  cout << "Denominator: ";
  cin >> d;	//stores denominator into d

  Rational R1(n,d);
  cout << "Your first rational is" << R1;

  cout << "Please enter another numerator and denominator." << endl << "Numerator: ";
  cin >> n; //stores numerator into n
  cout << "Denominator: ";
  cin >> d; //stores denominator into d

  Rational R2(n,d);
  cout << "Your two rationals are" << R1 << "and" << R2 << endl;

  //add them together
  cout << R1 << "+" << R2 << "=" << R1+R2 << endl << endl;

  //subtract them
  cout << R1 << "-" << R2 << "=" << R1-R2 << endl << endl;

  //multiply them
  cout << R1 << "*" << R2 << "=" << R1*R2 << endl << endl;

  //divide them
  cout << R1 << "/" << R2 << "=" << R1/R2 << endl << endl;

  //use the power function now
  cout << "Now we will use the exponent function. Please enter a power: ";
  cin >> power;
  cout << R1 << "^" << power << " = " << (R1^power) << endl;
  cout << R2 << "^" << power << " = " << (R2^power) << endl;
   
  cout << endl << "Thanks for playing!" << endl;
}
