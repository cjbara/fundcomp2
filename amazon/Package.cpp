//Package implementation

#include "Package.h"
#include <string>
#include <iostream>
using namespace std;

Package::Package(string first, string last, string addr, string zip, double w, double cost){
  firstName = first;
  lastName = last;
  address = addr;
  zipCode = zip;
  
  if(w<=0)	{ weight=1; }		//default weight is 1 ounce
  else { weight=w; }
  
  if(cost<0)	{ costPerOz=0.05; }	//default cost per ounce is 5 cents
  else {costPerOz = cost; } 
}

//below are all of the get functions
double Package::getWeight(){ return weight; } 
double Package::getCostPerOz(){ return costPerOz; }
string Package::getFirst(){ return firstName; }
string Package::getLast(){ return lastName; }
string Package::getAddress(){ return address; }
string Package::getZip(){ return zipCode; }

//two set functions set weight and cost per ounce, but only take positive values
void Package::setWeight(double w){
  if(w>0){ weight = w; }
}
void Package::setCostPerOz(double cost){
  if(cost>0){ costPerOz = cost; }
}

//returns the value of cost per ounce times weight
double Package::calcCost(){
  return costPerOz * weight;
}

void Package::print(){
  cout  << "Name: " << firstName << " " << lastName << endl
	<< "Address: " << address << endl
	<< "Zip code: " << zipCode << endl
	<< "Weight: " << weight << endl
	<< "Cost per Ounce: " << costPerOz << endl
	<< "Base Cost: " << calcCost() << endl;
}
