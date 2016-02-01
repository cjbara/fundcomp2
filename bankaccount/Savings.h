//Cory Jbara - Lab3 - Savings interface
//BankAccount is the root Class of this class Savings

#ifndef SAVINGS_H
#define SAVINGS_H
#include "BankAccount.h"

class Savings: public BankAccount{
  public:
    Savings(double=.05, double = 0, string = "No Name");
    virtual void print();
    int isMinimum();

  private:
    double rate;
    int isMin;

};

#endif
