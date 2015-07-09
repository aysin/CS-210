//
//
//Lab 5a, Array.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef Array_h
#define Array_h

#include <iostream>
using namespace std;


template <class DataType>
class Array
{
public:
  Array (int size); //done
  DataType& operator[] (int index); //done
  void changeSize (int newSize); //done
  int length() const; //done
  int lsearch (const DataType& value) const; //done
  string err() const; //done

  //for dynamic memory managment
  ~Array() { delete [] data; } // destructor done
  Array(const Array<DataType> &); // copy constructor
  Array<DataType>& operator =(const Array<DataType>& a); // assignment operator done


private:
  int capacity;
  int errorCode;
  DataType dummy;
  DataType* data; //dynamic array
};

template <class DataType>
Array<DataType>::Array(int size):capacity(size)
{
  errorCode = 0;
  
  if (capacity <= 0)
  {
    errorCode |= 1;
    data = 0;
  }
  else
    data = new DataType[capacity];
}

template <class DataType>
DataType& Array<DataType>::operator[](int index)
{
  errorCode = 0;
  if (index < 0)
  {
    errorCode |= 1;
    return dummy;
  }
  if (index >= capacity)
  {
    errorCode |= 2;
    return dummy;
  }
  return data[index];
}

template<class DataType>
void Array<DataType>::changeSize(int newSize)
{
  errorCode &= (7 - 4); // unset
  if (newSize <= 0)
    errorCode |= 4;
  else
  {
    DataType* newData = new DataType[newSize];
    int limit = newSize > capacity ? capacity : newSize;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete [] data;
    data = newData;
    capacity = newSize;
  }
}

// to access capacity
template<class DataType>
int Array<DataType>::length() const
{
  return capacity;
}

template<class DataType>
int Array<DataType>::lsearch(const DataType& parameter)const
{
  int result = -1; // not found
  
  for(int i = 0; i < capacity; i++)
  {
    if(data[i] == parameter)
      return i;
  }
  return result;
}

//error
template<class DataType>
string Array<DataType>::err() const
{
  if (errorCode == 0)
  {
    return "NO ERROR!\n";
  }
  string errMsg = " ";
}

template <class DataType>
Array<DataType>::Array(const Array<DataType>& a) // copy constructor
{
  capacity = a.capacity;
  errorCode = a.errorCode;
  data = 0;
  
  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
}


//overloadad operator
template <class DataType>
Array<DataType> & Array<DataType>::operator= (const Array<DataType>& a)
{
  if (this == &a){return *this;}

  delete [] data;
  capacity = a.capacity;
  errorCode = a.errorCode;
  data = 0;
  
  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
  return *this;
}




#endif