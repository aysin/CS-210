#include <iostream>
#include <algorithm>
using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h


template<class T>
class PriorityQueue
{
public:
  PriorityQueue();
  T& dequeue(T& );
  int getSize() const {return size;}
  void enqueue(const T& );
  void changeCapacity (int newCap);
  
  
private:
  int size;
  int capacity;
  T* data;
};

template<class T>
PriorityQueue<T>::PriorityQueue()
: size(0), capacity(2), data(new T[capacity]) {}

template<class T>
void PriorityQueue<T>::changeCapacity(int newCap)
{
    T* newData = new T[newCap];
    int limit = newCap > capacity ? capacity : newCap;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete [] data;
    data = newData;
    capacity = newCap;
  
}

template<class T>
void PriorityQueue<T>::enqueue(const T& a)
{
  int index = size;
  if (index >= capacity)
    changeCapacity(capacity);
  data[index] = a;
  
  for( ; index > 0; index--)
  {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0) break;
    if(parentIndex >= index) break;
    T temp = data[parentIndex];
    data[parentIndex] = data[index];
    data[index] = temp;
    index = parentIndex;
  }
  size++;
}

template<class T>
T& PriorityQueue<T>::dequeue(T& value)
{
  value = data[0];
  int index = 0;
  for (; index < capacity; index++)
  {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 1;
    if (leftChild >= size) break;
    if (leftChild >= size-1 || data[leftChild] >= data[rightChild])
    {
      data[index] = data[leftChild];
      index = leftChild;
    }
    else
    {
      data[index] = data[rightChild];
      index = rightChild;
    }
  }
  size--;
  if (size < capacity /4)
  {
    int newCapacity = capacity / 2;
    T* newData = new T[newCapacity];
    int limit = newCapacity > capacity ? capacity : newCapacity;
    for (int i = 0; i < limit; i++) newData[i] = data[i];
    delete [] data;
    data = newData;
    capacity /= 2;
  }
  //copy value at size into array at index
  data[index] = data[size];
  
  for (int i = 0; i < capacity; i ++)
  {
    int parentIndex = (index +1) / 2 -1;
    if(parentIndex < 0) break;
    if(parentIndex >= index) break;
    T temp = data[parentIndex];
    data[parentIndex] = data[index];
    data[index] = temp;
    index = parentIndex;
  }
  return value;
}



#endif