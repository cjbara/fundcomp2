/* Cory Jbara - Fund Comp 2 - Lab 1
 * Interface for class C4Col */

#ifndef C4COL_H
#define C4COL_H

class C4Col{

  public:
    C4Col();
    int isFull();
    char getDisc(int);
    int getMaxDiscs();
    int addDisc(char);
    C4Col operator+=(char);

  private:
    int numDiscs;
    int maxDiscs;
    char discs[6];
};

#endif

