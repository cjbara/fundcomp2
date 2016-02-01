#include "C4Board.h" // class definition for C4Board used below
#include <iostream>
using namespace std;

int main() {
  C4Board c4; // instantiate an instance of a C4Board object c4.play(); // play game!!
  cout << "How many players? (1 or 2) ";
  int players=0;
  while(players!=1 && players!=2){ cout << "Please enter 1 or 2: "; cin >> players; }
  c4.display();
  c4.play(players);
}
