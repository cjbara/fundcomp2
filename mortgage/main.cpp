//Cory Jbara -  Fund Comp 2 - Prelab
//Driver program for mortgage calculator

#include <iostream> // for cout
using namespace std; 
#include "mortgage.h" // declaration of Mortgage class; for 2a

int main () {
  //create four new mortgages, one using default constructor, two display error message
  Mortgage one(300000,.01,3200);//this one will work
  cout << "Mortgage two: ";
  Mortgage two(100000,.5,200);	//this one has a rate too large for the monthly payment and will display an error message
  cout << "Mortgage three: ";
  Mortgage three(100000,-2,500);//will display negative rate error
  Mortgage four;		//default constructor, will have 100000 with 5% and $500 payment

  one.credit(50000);//This credits the first mortgage $50,000, will reduce initial principle to $250,000

  cout << "Fourth mortgage balance: $" << four.getPrincipal() << endl;
  cout << "Current balance after crediting mortgage one 50K: $" << one.getPrincipal() << endl;
  cout << "Amortization schedule for first mortgage:" << endl;
  one.amortize(); 
}
