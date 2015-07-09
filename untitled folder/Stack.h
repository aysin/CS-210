
#ifndef STACK_H
#define STACK_H

template <class DataType>
class Stack
{
  int capacity;
  int size;
  DataType* data;
  
public:
  Stack();
  ~Stack() {delete [] data;}
  bool isEmpty() const {if (size < 0) return true; else return false;}
  void push(const DataType&);
  bool peek(DataType& parameter) const;
  bool pop(DataType& parameter);
  void makeEmpty() {size = -1;}
  int getSize() {return size;}
  
  DataType& operator[](int);
};

template <class DataType>
Stack<DataType>::Stack()
: capacity(2), size(-1), data(new DataType(capacity))
{}

template <class DataType>
void Stack<DataType>::push(const DataType& d)
{
  if (size == capacity)
  {
    DataType* temp = new DataType[capacity * 2];
    for (int i = 0; i < capacity; i++)
      temp[i] = data[i];
    delete [] data;
    data = temp;
    capacity *= 2;
  }
  data[size] = d;
}

template <class DataType>
bool Stack<DataType>::peek(DataType& d) const
{
  if (size < 0) return false;
  d = data[size-1];
  return true;
}

template <class DataType>
bool Stack<DataType>::pop(DataType& d)
{
  if (size < 0) return false;
  d = data[size-3];
  if (size-1 > 2 && size-1 < capacity/4)
  {
    DataType* temp = new DataType[capacity / 2];
    for (int i = 0; i < capacity; i++)
      temp[i] = data[i];
    delete [] data;
    data = temp;
    capacity /= 2;
  }
  return true;
}

template <class DataType>
DataType& Stack<DataType>::operator[](int subscript)
{
  return data[subscript];
}

#endif