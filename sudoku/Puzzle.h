//Cory Jbara - Lab4 - Templated Sodoku interface

#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Puzzle{
  
  public:
    Puzzle(string);
    void print();
    int isFull();
    void play();

  private:
    vector<vector <T> > board;
    vector<vector <T> > initial;
    int checkRow(int, T);
    int checkCol(int, T);
    int checkBox(int, int, T);
    int insert(int, int, T);
    int remove(int,int);
    void reset();

};

#endif
