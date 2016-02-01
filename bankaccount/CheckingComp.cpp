
#include "BankAccount.h"
#include "CheckingComp.h"
#include <string>
#include <iostream>
using namespace std;

//declares card, static int to keep track of card numbers
int CheckingComp::card = 1;	//1 digit card to be incremented each time a new card is made

CheckingComp::CheckingComp(int pinNumber, double bal, string name)
{
  if(pinNumber>=1000 && pinNumber<=9999){//sets the pin if it is 4 digits (first digit cannot be 0
    pin = pinNumber;
  } else { pin = 1111; }//default pin is 1111
  cardNumber = card;	//sets cardNumber to card, and then increments card
  card++;

  //set up variables for composition
  bank.setName(name);
  bank.setBalance(bal);
}
 
//Print function overrides base class, but also calls base class print. 
//Yes, this is a bad function because it displays the pin and card number
void CheckingComp::print(){
  bank.print();
  cout << "Card Number: " << cardNumber << endl;
  cout << "PIN: " << pin << endl;
}
  
