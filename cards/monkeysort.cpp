//Cory Jbara - lab 4
//Driver program for part 2 - makes 10 card deck, ensures they are in order
//prints, shuffles, then prints again

#include "CardDeck.h"
#include <iostream>
using namespace std;

int main(){
  
  //create a deck and shuffle it, then monkey sort it
  CardDeck d7(7);
  CardDeck d8(8);
  CardDeck d9(9);
  cout << "With a 7 card deck:" << endl;
  for(int i=0; i<3; i++) {
	d7.monkeySort();
  }
  cout << endl << "With an 8 card deck:" << endl;
  for(int i=0; i<3; i++) {
	d8.monkeySort();
  }
  cout << endl << "With a 9 card deck:" << endl;
  for(int i=0; i<3; i++) {
	d9.monkeySort();
  }

}
