//Two Day package class interface
//TwoDay is a derived class of Package

#ifndef TWODAY_H
#define TWODAY_H
#include "Package.h"
#include <string>
using namespace std;

class TwoDay: public Package
{
  public:
    TwoDay(double,string,string,string,string,double,double);
    virtual double calcCost(); //same as packages calcCost() but with extra fee
   
    double getExtraFee();//returns extra fee

    virtual void print();//overrides Package's print function

  private:
    double extraFee;
    
};

#endif
