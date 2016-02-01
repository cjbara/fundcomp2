//Cory Jbara - Lab3 - BankAccount interface
//BankAccount is the root Class, from which many derived classes will be made

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;

class BankAccount{
  public:
    BankAccount(double=0,string="No Name");

    double getBalance();
    void setBalance(double);

    int getAccount();

    string getName();
    void setName(string);

    virtual void print();

  private:
    static int number;
    int accountNumber;
    double balance;
    string accountName;

};

#endif
