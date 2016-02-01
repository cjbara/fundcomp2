//Cory Jbara's NDVector class implementation

#include "NDVector.h"
#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

template <typename T>
NDVector<T>::NDVector(long int initialCapacity){
  //set the size = 0 
  dataSize = 0;

  //capacity is number of initialCapacity if initialCapacity is valid 
  if(initialCapacity>0){
    dataCapacity = initialCapacity;
  } else {
    dataCapacity=10;
    initialCapacity=10;
  }

  //try to initialize the data array
  try {
    data = new T[initialCapacity];
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "Not enough memory! Allocating 10 elements." << endl; 
    data = new T[10];
    dataCapacity = 10;
  }
}

//deconstructor
template <typename T>
NDVector<T>::~NDVector(){
  delete [] data;
}

//copy constructor
template <typename T>
NDVector<T>::NDVector(const NDVector &oldVec){
  dataSize = oldVec.dataSize;
  dataCapacity = oldVec.dataCapacity;
  data = oldVec.data;
}

template <typename T>
void NDVector<T>::pop_back(){
  //remove the last element
  if(dataSize>0){
    data[dataSize-1]=0;
    dataSize--;
  } else {
    throw exception();
  }
}

template<typename T>
int NDVector<T>::size(){
  return dataSize;
}

template<typename T>
int NDVector<T>::capacity(){
  return dataCapacity;
}

template<typename T>
T NDVector<T>::front(){
  if(size() > 0){  return data[0];  }
  else { throw exception(); }
}

template<typename T>
T NDVector<T>::back(){
  if(size() > 0){  return data[dataSize-1];  }
  else { throw exception(); }
}

template <typename T>
void NDVector<T>::increaseCapacity(){
  dataCapacity *= 2;
 
  //store all elements of data into newData, and then reallocate memory for data
  T *newData = new T[dataCapacity];
  for(int i=0; i<dataSize; i++){
    newData[i] = data[i];
  }

  //now reallocate memory for data
  delete data;
  data = newData;
  
}

template <typename T>
void NDVector<T>::clear(){
  //remove every element from data
  for(int i=0; i<dataSize; i++){
    data[i] = 0;
  }
  dataSize = 0;
}

template<typename T>
void NDVector<T>::push_back(T element){
  //if the size == capacity, increase capacity
  if(dataSize == dataCapacity){
    increaseCapacity();
  }
  data[dataSize] = element;
  dataSize++;
}

template<typename T>
void NDVector<T>::push_front(T element){
  //if the size == capacity, increase capacity
  if(dataSize == dataCapacity){
    increaseCapacity();
  }
  
  //push every element back one
  for(int i = dataSize-1; i>=0; i--){
    data[i+1] = data[i];
  }
  //now add the new element
  data[0] = element;
  dataSize++;
}

template<typename T>
T &NDVector<T>::operator[](int index){
    if(index>=0 && index<dataSize){
      return data[index];
    } else {
      throw exception(); // generate exception because of bad index
    }
}

template<typename T>
void NDVector<T>::operator=(NDVector &vec){
  //set all elements equal
  dataSize = vec.size();

  //if you need to add more space, do it (while there is not enough space
  while(dataCapacity <= vec.size()){
    increaseCapacity();
  }

  //set all the elements equal to the elements from the other vector
  for(int i=0; i<vec.size(); i++){
    data[i] = vec[i];
  }
}

template<typename T>
void NDVector<T>::print(){
  cout << "[";
  for(int i=0; i<size(); i++){
    cout << data[i] << ((i<size()-1)? " ":"");
  }
  cout << "]" << endl;
} 

template <typename T>
T NDVector<T>::operator!(){
  //returns the max value of vector
  T max=data[0];
  for(int i=1; i<size(); i++){
    if(data[i]>max){
	max = data[i];
    }
  }
  return max;
}

template <typename T>
NDVector<T> &NDVector<T>::operator+(NDVector<T> &vector2){
  //concatenate the two vectore, put vector2 at the end
  for(int i=0; i<vector2.size(); i++){
    this->push_back(vector2[i]);
  }
  return (*this);
}

template <typename T>
void NDVector<T>::sort(){
  //use basic insertion sort
  for(int i=1; i<size(); i++){
    int j=i;
    while(j>0 && data[j-1]>data[j]){
	//swap the points
	T temp = data[j-1];
	data[j-1] = data[j];
	data[j] = temp;
	j--;
    }
  }
}

template <typename T>
void NDVector<T>::random_shuffle(){
  int k;
  T temp;
  
  for(int i=size()-1; i>0; i--){
    k=rand()%i; //pick a random number from 0 to i-1
    //swap data[i] and data[k]
    temp = data[i];
    data[i] = data[k];
    data[k] = temp;
  }
}
  

//The explicit instantiation
template class NDVector<int>;
template class NDVector<char>;
template class NDVector<float>;
template class NDVector<double>;

