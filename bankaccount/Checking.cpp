
#include "BankAccount.h"
#include "Checking.h"
#include <string>
#include <iostream>
using namespace std;

//declares card, static int to keep track of card numbers
int Checking::card = 1;	//1 digit card to be incremented each time a new card is made

Checking::Checking(int pinNumber, double bal, string name)
  :BankAccount(bal, name)
{
  if(pinNumber>=1000 && pinNumber<=9999){//sets the pin if it is 4 digits (first digit cannot be 0
    pin = pinNumber;
  } else { pin = 1111; }//default pin is 1111
  cardNumber = card;	//sets cardNumber to card, and then increments card
  card++;
}
 
//Print function overrides base class, but also calls base class print. 
//Yes, this is a bad function because it displays the pin and card number
void Checking::print(){
  BankAccount::print();
  cout << "Card Number: " << cardNumber << endl;
  cout << "PIN: " << pin;
}
  
