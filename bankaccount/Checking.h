//Cory Jbara - Lab3 - BankAccount interface
//BankAccount is the root Class of this class Checking

#ifndef CHECKING_H
#define CHECKING_H

class Checking: public BankAccount{
  public:
    Checking(int,double,string);
    string getCard(int);	//input pin and return debitNumber
    virtual void print();	//overrides BC function call
  
  private:
    static int card;
    int pin;
    int cardNumber;

};

#endif
