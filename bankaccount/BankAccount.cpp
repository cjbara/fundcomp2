
#include "BankAccount.h"
#include <iostream>
using namespace std;

//these functions have to do with setting up new accounts and giving them new account numbers
int BankAccount::number=1000000;	//beginning account number (initialized)

BankAccount::BankAccount(double initial, string name){
  balance=initial;	//set balance
  accountName=name;	//set name of account owner
  accountNumber= number;	//account number is set to number
  number++;		//increment number for next new account
}

//get/set balance function
double BankAccount::getBalance(){	return balance;	}
void BankAccount::setBalance(double bal){
  if(bal>0){ balance=bal; }
}

//This function returns the account number for a class
int BankAccount::getAccount(){    return accountNumber; }

//Get/set functions for name on account
string BankAccount::getName(){	return accountName;	}
void BankAccount::setName(string newName){	accountName = newName;	}

//prints out account number, name and balance (can be overriden by derived classes)
void BankAccount::print(){
  cout 	<< "Account Number: " << getAccount() << endl
	<< "Account Name: " << getName() << endl
	<< "Account Balance: $" << getBalance() << endl;
}

