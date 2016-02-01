//Cory Jbara -  Fund Comp 2 - Prelab
//Mortgage calculator implementation includes functions in the Mortgage class

#include <iostream>
using namespace std;
#include "mortgage.h"
#include <iomanip>

//Default constructor assigns all three values to default
Mortgage::Mortgage(){
  principal=100000;  //Sets values to default ($10000, .05 yearly rate, $500 monthly payment)
  rate=.05/12;
  payment=500;
}

//non-default constructor uses parameters to assign values to principal, rate, and payment
Mortgage::Mortgage(double p, double r, double pay){//r is yearly rate
 int valid=0;

 //Check if these are valid inputs
 if((p*r/12)>=pay){//This causes the monthly payment to be too small, do not update class values
  cout << "Payment is too small for interest rate." << endl;
 } else if (r<0){//rate is too small
  cout << "Rate must be greater than or equal to 0." << endl;
 } else {
  valid=1;
  principal=p;	//Sets values in class to user inputs p,r, and pay
  rate=r/12;	//since r is yearly rate, divide by 12
  payment=pay;
 }  

 if(valid==0){
  principal=10000;  //Sets values to default ($10000, .05 yearly rate, $500 monthly payment)
  rate=.05/12;
  payment=500;
 }
}

void Mortgage::credit(double value){//this function deducts the given value from the remaining principal
  principal-=value;
  if(principal<0) principal=0;	//makes sure principal isn't negative
}

double Mortgage::getPrincipal(){//this function returns the current principal
  return principal;
}

void Mortgage::amortize(){	//Displays a table for the mortgage payment
  int month=1;
  double interest;			//interest value per month
  double balance=principal;
  cout << "Month\tPayment\t\tInterest\tBalance" << endl;	//Sets up table
  while(balance>0){
    interest = rate*balance;			//updates interest value
    balance += interest;			//updates balance
    if(balance<payment){
	payment=balance;
	balance=0;
    } else {
	balance -= payment;
    }

    cout << month << "\t";						//Inserts month number
    cout << "$" << fixed << setprecision(2) << payment << "\t";	//Inserts monthly payment
    cout << "$" << fixed << setprecision(2) << interest << "\t\t";	//Inserts interest payment
    cout << "$" << fixed << setprecision(2) << balance << "\t" << endl;	//Inserts remaining balance
    month++;
  }
}

