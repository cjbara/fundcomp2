//Cory Jbara - Lab3 part 1 - Savings implementation

#include "Savings.h"
#include <string>
#include <iostream>
using namespace std;

Savings::Savings(double intrate, double bal, string name)
  :BankAccount(bal, name)
{
  if(intrate>0 && intrate<1){ rate = intrate; }
  else rate = .05;	//default rate is 5%
}

void Savings::print(){
  BankAccount::print();
  cout << "Interest Rate: " << rate;
}

int Savings::isMinimum(){
  if(getBalance()<5){
    isMin=0;	//does not meet the minimum balance requirement of $5
  } else {isMin=1;}
  return isMin;
}
