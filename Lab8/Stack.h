//
//
//Lab 8a Stack.h
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef STACK_H
#define STACK_H
#include <cassert>

template<class DataType>
class Stack
{
private:
  DataType* data;
  int capacity;
  int top;
  
public:
  Stack();  //1 constructor
  Stack(const Stack<DataType>&);  //2 copy constructor
  ~Stack() { delete [] data;}  //3 destructor
  Stack<DataType>& operator=(const Stack<DataType>& ); // 4 operator
  void changeCapacity(int ); // 5 change Cap
  
  //stack operations
  void push(const DataType& );
  bool pop(DataType&);
  bool isEmpty() const;
  void makeEmpty();
  bool peek(DataType& ) const;

};

// 1 Constructor
template <class DataType>
Stack<DataType>::Stack()
: capacity(2), data(new DataType[2]), top(-1){}

//2 Copy Constructor
template <class DataType>
Stack<DataType>::Stack(const Stack<DataType>& a)
: capacity(a.capacity), data(0), top(a.top)
{
  if (capacity > 0)
    data = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
    data[i] = a.data[i];
}


//4 operator
template <class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a)
{
  if (this != &a)
  {
    delete [] data;
    data = 0;
    capacity = a.capacity;
    if (capacity > 0)
      data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
    top = a.top;
  }
  return *this;
}

//5 change size
template <class DataType>
void Stack<DataType>::changeCapacity(int newCapacity)
{
  assert(newCapacity > 0); // requires cassert library
  DataType* newData = new DataType[newCapacity];
  int limit = newCapacity > capacity ? capacity : newCapacity;
  for (int i = 0; i < limit; i++) newData[i] = data[i];
  delete [] data;
  data = newData;
  capacity = newCapacity;
}

//Check if array is empty
template <class DataType>
bool Stack<DataType>::isEmpty() const {return -1 == top;}

//Make the Stack empty
template <class DataType>
void Stack<DataType>::makeEmpty() {top = -1;}

//push
template <class DataType>
void Stack<DataType>::push(const DataType& parameter)
{
  if(++top == capacity) //double the capacity as in Array
  {
    DataType* temp = new DataType[capacity * 2];
    for(int i = 0; i < capacity; i++)
      temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity *= 2;
  }
  
  data[top] = parameter;
}


//pop
template <class DataType>
bool Stack<DataType>::pop(DataType& parameter)
{
  if (-1 == top)
    return false; // failed
  parameter = data[top--];
  if (top > 2 && top < capacity / 4) //halve the capacity
  {
    DataType* temp = new DataType[capacity / 2];
    for (int i = 0; i < capacity; i++)
      temp[i] = data[i];
    delete [] data;
    data = temp;
    capacity /= 2;
  }
  
  return true; // success
}

//peek
template <class DataType>
bool Stack<DataType>::peek(DataType& parameter) const
{
  if (-1 == top) return false; // failed
  parameter = data[top];
  return true; // success
}




#endif