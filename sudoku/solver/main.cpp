//driver program for sudoku
//inputs a puzzle and prints the puzzle

#include "Puzzle.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
  //get inputs from puzzle.txt
  string fileName="puzzle.txt";

  //create a new Puzzle 
  Puzzle<int> p(fileName);

  //print the puzzle unsolved, and then solve it
  p.print();
  p.solve();

  return 0;

}
