//NDVector is a custom made vector
#include <iostream>
using namespace std;

#ifndef NDVECTOR_H
#define NDVECTOR_H

template <typename T>
class NDVector {

  public:
    //constructor/deconstructor/copy constructor
    NDVector(long int=10);
    ~NDVector();
    NDVector(const NDVector &);

    //Adds an element to the front of the vector
    void push_front(T);

    //Adds an element to the back of the vector
    void push_back(T);

    //Removes an element from back
    void pop_back();

    //Returns the current size of the vector
    int size();

    //Returns the capacity of the vector
    int capacity();

    //Access front element
    T front();

    //Access back element
    T back();

    //Clear NDVector
    void clear();

    //Print the whole vector
    void print();

    //Assignment operator
    void operator=(NDVector<T> &);

    //Random access operator
    T& operator[](int);

    //Max operator !
    T operator!();

    //Concatenation operator +
    NDVector<T>& operator+(NDVector<T> &);
 
    //Sort function sorts the list of elements
    void sort();

    //Randomly shuffles the vector
    void random_shuffle();

  private:
    int dataSize;
    int dataCapacity;
    T *data;
    void increaseCapacity(); //doubles capacity of data

};

#endif

