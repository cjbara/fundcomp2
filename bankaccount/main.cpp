#include "BankAccount.h"
#include "Checking.h"
#include "Savings.h"
#include "CheckingComp.h"
#include <iostream>
using namespace std;

int main()
{
  
  Checking newCheck(4567,10000,"Cory Jbara");
  Savings newSave(.04,1000, "CJ");
  BankAccount newBank(1500, "Cory");

  BankAccount *BAptr;

//uses polymorphism to call the different virtual functions
//will call Checking's version of the print function
  cout << "\n\nChecking Account Print function." << endl;
  BAptr= &newCheck;
  BAptr->print();

  cout << "\n\nSavings Account Print function." << endl;
  BAptr= &newSave;
  BAptr->print();

  cout << "\n\nDefault Bank Account Print function." << endl;
  BAptr= &newBank;
  BAptr->print();

  
  //Now use the composition class CheckingComp with data member bank (of type BankAccount)
  //Use this object's print function
  cout << "\nComposition Checking Print function." << endl;
  CheckingComp newCheckComp(2345,5000,"John Smith");
  newCheckComp.print();


  return 0;
}

