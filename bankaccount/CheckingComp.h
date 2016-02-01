//Cory Jbara - Lab3 - BankAccount interface
//BankAccount is the root Class of this class Checking

#ifndef CHECKING2_H
#define CHECKING2_H

class CheckingComp{
  public:
    CheckingComp(int,double,string);
    string getCard(int);	//input pin and return debitNumber
    virtual void print();	//overrides BC function call
  
  private:
    BankAccount bank;
    static int card;
    int pin;
    int cardNumber;

};

#endif
