//Implementation for OVernight class

#include "Overnight.h"
#include <string>
#include <iostream>
using namespace std;

Overnight::Overnight(double extraPerOz, string first, string last, string addr, string zip, double w, double cost)
  :Package(first, last, addr, zip, w, cost)
{
  if(extraPerOz>0){ extraCostPerOunce = extraPerOz; }
  else { extraCostPerOunce = 0; }
  //if the extra cost is negative, then make it 0
}

//gets initial cost, then adds extra fee per ounce times weight
double Overnight::calcCost(){
  return extraCostPerOunce * getWeight() + Package::calcCost();
}

//returns extracost
double Overnight::getExtraPerOunce(){ return extraCostPerOunce; }

//new print function overrides old print funciton from package base class
void Overnight::print(){
  Package::print();
  cout << "Extra Cost per Ounce: " << getExtraPerOunce() << endl
	<< "Total cost: " << calcCost() << endl;
}
