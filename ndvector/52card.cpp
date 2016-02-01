//Cory Jbara - lab 4
//Driver program for part 2 - makes 10 card deck, ensures they are in order
//prints, shuffles, then prints again

#include "CardDeck.h"
#include <iostream>
using namespace std;

int main(){

  //create new deck
  CardDeck newDeck(52);

  //are they in order?
  if(newDeck.inOrder()){
	cout << "Yes, the cards are in order." << endl;
  } else {
	cout << "No, they are not in order." << endl;
  }

  //print the cards
  cout << newDeck; 
 
  //shuffle the cards
  cout << "The cards are shuffling." << endl;
  newDeck.shuffle(); 

  //print the cards again
  cout << newDeck;
  if(newDeck.inOrder()){
        cout << "Yes, the cards are in order." << endl;
  } else {
        cout << "No, they are not in order." << endl;
  }
}
