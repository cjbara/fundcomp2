/* Cory Jbara - Fund Comp 2 - Lab 1
 * Implementation for class C4Col */

#include "C4Col.h"
#include <iostream>
using namespace std;

//Default constructor
C4Col::C4Col(){
  maxDiscs=6;
  numDiscs=0;
  for(int i=0;i<maxDiscs;i++){
    discs[i]=' ';
  }
}

//isFull returns 1 if the column is full, otherwise it returns 0
int C4Col::isFull(){
  if(numDiscs==maxDiscs){
    return 1;
  } else { return 0; } 
}

//getDisc returns the requested element of the Disc array
char C4Col::getDisc(int d){	//d is the requested disc to be returned
  if(d<maxDiscs){
    return discs[d];
  } else {
    cout << "This is not a space in the column." << endl;
  }
}

//getMaxDiscs returns the data member maxDiscs
int C4Col::getMaxDiscs(){
  return maxDiscs;
}

//addDisc checks if the column is full and if it is not, 
//adds a new disc to the first place in Disc
int C4Col::addDisc(char d){	//d is the char of the disc to be added
  if(numDiscs<maxDiscs){	//column is not full, add disc
    discs[numDiscs++]=d;
    return 0;
  } else {
    cout << "This column is full, you cannot place another disc here." << endl;
    return 1;
  }
}
    
C4Col C4Col::operator+=(char newDisc){
  addDisc(newDisc);
  return (*this);
}
