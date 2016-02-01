//Cory Jbara - lab 4
//Implementation for the CardDeck class
//the last 2 functions are for the blackjack implementation
//Deal() deletes members of the deck until it is less than 15 cards, then reshuffles using newDeck()

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "CardDeck.h"
using namespace std;

CardDeck::CardDeck(int n){
  //creates deck with numbers 0 through n-1 in it
  deckSize = n;
  for(int i=0; i<n; ++i){
    deck.push_back(i);
  }
  srand(time(NULL));
}

//This function returns the size of the deck
int CardDeck::getSize(){
  return deck.size();
}

//This function "shuffles the deck" by rearranging all the values with 
//STL's random_shuffle algorithm
void CardDeck::shuffle(){
  random_shuffle(deck.begin(),deck.end());
}

int CardDeck::inOrder(){
  for(int i=0; i<getSize()-1; i++){
    //if the next is greater than the previous for any value, return 0
    if(deck[i]>deck[i+1]){
	return 0;
    //otherwise return 1
    } 
  }
  //if the for loop did not catch it, then it is in order, so return 1
  return 1;
}

//Monkey sort uses the shuffle() function to shuffle the deck unitl inOrder() returns 1
//It counts the number of shuffles it does and then returns/outputs that value
int CardDeck::monkeySort(){
  int shuffleNumber=0;
  //shuffled is a deque, which will be assigned the value of deck, and will be shuffled
  do {
    shuffle();
    shuffleNumber++;
  } while(!inOrder());
  cout << "It took " << shuffleNumber << " shuffles to sort the deck." << endl;
  return shuffleNumber;
}

//This function overloads the << to display the whole deck separated by commas
ostream & operator<<(ostream &output, CardDeck &Deck){
  deque<int>::const_iterator i=Deck.deck.begin();
  //for each member of the deck, print out the number and comma space 
  for(i; i!=Deck.deck.end(); ++i){
    //if not the first card, print a comma
    if(i!=Deck.deck.begin()){
	cout << ", ";
    }
    //print the card
    output << *i;
  }
  //ends the line with a newline
  output << endl;
  return (output);
}

//This next part will all be for blackjack
int CardDeck::Deal(){
  //chooses the first card in the deck to deal
  int card = deck[0];

  //deletes the card just dealt
  deck.pop_front();

  //if the deck is smaller than 15, create new deck
  if(getSize()<15){
    newDeck();
  }

  //"deals" the card
  return card;
}

//creates a new deck by flushing the old deck, filling it with a new deck,
//and shuffling
void CardDeck::newDeck(){
  //clear deck
  deck.clear();
  //fill with new deck
  for(int i=0; i<deckSize; ++i){
    deck.push_back(i);
  }
  //shuffle
  //also display that the cards have been shuffled
  cout << endl << "SHUFFLING" << endl << endl;
  shuffle();
}
