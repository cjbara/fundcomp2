//Implementation for TwoDay class

#include "TwoDay.h"
#include <string>
#include <iostream>
using namespace std;

TwoDay::TwoDay(double fee,string first, string last, string addr, string zip, double w, double cost)
  :Package(first, last, addr, zip, w, cost)
{
  if(fee>0){
    extraFee = fee;
  } else { extraFee = 0; }	//default extra fee is 0
}

double TwoDay::calcCost(){
  return Package::calcCost() + extraFee;
}

double TwoDay::getExtraFee() { return extraFee; }

void TwoDay::print(){
  Package::print();
  cout  << "Extra Fee for two day shipping: " <<extraFee << endl
	<< "Updated total cost: " << calcCost() << endl;
}
