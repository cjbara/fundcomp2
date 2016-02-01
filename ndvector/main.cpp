#include "NDVector.h"
#include <iostream>
using namespace std;

int main()
{

  NDVector<int> vec(100000000000000000);
  NDVector<int> vec2(1);

  vec.push_back(23);
  vec.push_front(45);
  vec.push_back(10);
  vec.push_back(15);

  //bad indexing example
  try{  cout << "vec[-1]=" << vec[-1] << endl;
  } catch(exception &e){
    cout << endl << "Could not access vec[-1], index out of bounds" << endl;
  }

  cout << endl << "vec = ";
  vec.print(); 

  cout << "Setting vec2 = vec1" << endl;
  vec2 = vec;
  cout << "vec2 = ";
  vec2.print();
  cout << endl;

  cout << "Pushing 211 to the front of vec2" << endl; 
  vec2.push_front(211);
  cout << "vec2=";vec2.print(); cout << endl;
 
  cout << "Concatenating vec1 + vec2 + vec2" << endl;
  cout << "vec1=";vec.print();
  cout << "vec2=";vec2.print();
  vec+vec2+vec2;
  cout << "vec1 + vec2 + vec2 =";vec.print();

  //try to pop-back on empty vector
  vec2.clear();
  try{ vec2.pop_back(); }
  catch (exception &e) {
    cout << endl << "Vector is empty, could not pop_back" << endl;
  }
  //try to access front element on empty vector
  try{ vec2.front(); }
  catch (exception &e){
    cout << endl << "Could not access front, vector is empty" << endl;
  }
  cout << endl << "Sorting vec1" << endl;
  vec.sort();
  cout << "Sorted vec1: ";  
  vec.print();

  cout << "Max of vec1 = " << !vec << endl;
}
