//Package interface

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package{
  public:
    //constructor includes values for first, last, address, zipcode, 
    //and doubles for weight and cost per ounce
    Package(string,string,string,string,double,double);
    virtual double calcCost();	//calculates the cost of a standard package
    
    double getWeight(); //returns weight
    void setWeight(double);//sets weight

    double getCostPerOz();//returns costPerOz
    void setCostPerOz(double);//sets cost per ounce
  
    //these return their associated variable
    string getFirst();
    string getLast();
    string getAddress();
    string getZip();

    virtual void print();//print function can be overriden by derived classes

  private:
    string firstName;
    string lastName;
    string address;
    string zipCode;

    double weight; //weight of package in ounces
    double costPerOz; //cost of  package in ounces

};

#endif
