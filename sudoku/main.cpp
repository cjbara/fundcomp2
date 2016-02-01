//driver program for sudoku
//inputs a puzzle and prints the puzzle

#include "Puzzle.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

  string fileName="puzzle.txt";
  string file2="puzzle2.txt";
/*
  cout << "Please enter a file name: ";
  cin >> fileName;
*/
  Puzzle<int> p(fileName);
  Puzzle<char> c(file2);

  cout << "Puzzle p uses ints" << endl;
  p.print();
  cout << "Puzzle c uses chars" << endl;
  c.print();

  cout << "Now we will play a game of sudoku with puzzle p:" << endl;
  p.play();


  return 0;

}
