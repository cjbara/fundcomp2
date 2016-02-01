//New class overnight is derived class of Package
//charges extra for shipping per ounce
//Interface for Overnight class

#ifndef OVERNIGHT_H
#define OVERNIGHT_H
#include "Package.h"
#include <string>
using namespace std;

class Overnight: public Package
{
  public:
    Overnight(double,string,string,string,string,double,double);
    virtual double calcCost(); //calculates cost with new extra cost per ounce

    double getExtraPerOunce();//returns extra fee per ounce

    virtual void print();//overrides Package's function

  private:
    double extraCostPerOunce;

};

#endif
