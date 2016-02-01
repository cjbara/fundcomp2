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
    void play();
    void solve();

  private:
    vector<vector <T> > board;
    vector<vector <T> > initial;
    vector<vector<vector <T> > > possible;
    int checkRow(int, T);
    int checkCol(int, T);
    int checkBox(int, int, T);
    int check(int, int, T);
    void insert(int, int, T);
    int remove(int,int);
    void reset();
    int isFull();
    int unfilled();
    void singletonCol();
    void singletonRow();
    void singletonBox();

};

#endif
