//
//
//Lab 14, SortableArray.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef SortableArray_h
#define SortableArray_h

#include <iostream>
using namespace std;

template <class DataType>
class SortableArray
{
public:
  //for dynamic memory managment
  ~SortableArray() { delete [] data; } // destructor done
  SortableArray(const SortableArray<DataType> &); // copy constructor
  SortableArray<DataType>& operator =(const SortableArray<DataType>& a); // assignment operator done
  SortableArray (int);
  DataType& operator[] (int);
  void changeSize (int);
  int length() const;
  string err() const;
  int lsearch (const DataType& ) const;
  void sort(int, int);
  int bsearch (const DataType&) const; //binary search
  void sort(int = -1); // quick sorts  
  
private:
  int capacity;
  int errorCode;
  DataType dummy;
  DataType* data; //dynamic SortableArray
  int bsearch2(const DataType& data, int s, int e) const;
};

template <class DataType>
SortableArray<DataType>::SortableArray(int size):capacity(size)
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
DataType& SortableArray<DataType>::operator[](int index)
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
void SortableArray<DataType>::changeSize(int newSize)
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
int SortableArray<DataType>::length() const
{
  return capacity;
}

//linear search
template<class DataType>
int SortableArray<DataType>::lsearch(const DataType& parameter)const
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
string SortableArray<DataType>::err() const
{
  if (errorCode == 0)
  {
    return "NO ERROR!\n";
  }
  string errMsg = " ";
}

template <class DataType>
SortableArray<DataType>::SortableArray(const SortableArray<DataType>& a) // copy constructor
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
SortableArray<DataType> & SortableArray<DataType>::operator= (const SortableArray<DataType>& a)
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

template <class DataType>
int SortableArray<DataType>::bsearch2(const DataType& data2, int s, int e) const
{
  // "a" is an array of type DataType
  // "value" is the DataType value to be matched
  // "s" is the starting index of the array (usually 0)
  // "e" is the ending index of the array (usually size-1)
  
  DataType value = data2;
  
  int m = (s + e) / 2; // the middle element
  if (value == data[m]) // got lucky -- matches middle element
  {
    value = data[m]; // copy whole struct (if DataType's a struct)
    return m; // return index of found element
  }
  else if (s == e) // 1-element array
    return -1; // only element in array did not match
  else if (value < data[m]) // look between s and m-1
  {
    if (s == m) return -1; // but that range is empty, no match
    else return bsearch2(value, s, m - 1); // look in s to m-1
  }
  else // look between m+1 and e
  {
    if (m == e) return -1; // but that range is empty, no match
    else return bsearch2(value, m + 1, e); // look in m-1 to e
  }
}


template <class DataType>
int SortableArray<DataType>::bsearch(const DataType& data) const
{
  int result = -1;
  
  result = bsearch2( data, 0, capacity );
  
  return result;
}

template <class DataType>
void SortableArray<DataType>::sort(int size) // quicksort
{
  if (size < 0)
    sort(0, capacity);
  else
    sort(0, size);
}

template <class DataType>
void SortableArray<DataType>::sort(int s, int e)
{
  if (s >= e) return; // done!
  int pivot = (s + e) / 2;
  int l = s; // index of left-most element
  int r = e; // index of right-most element
  
  while (true)
  {
    while(l < pivot)
      if (data[pivot] < data[l]) break; else ++l;
    while(pivot < r)
      if (data[r] < data[pivot]) break; else --r;
    if (l == r) // balanced
    {
      sort(s, pivot - 1);
      sort(pivot + 1, e);
      break; // done
    }
    else if (l == pivot) // swap w/pivot
    {
      DataType temp = data[pivot];
      data[pivot] = data[r];
      data[r] = temp;
      pivot = r;
      ++l;
    }
    else if (pivot == r) // swap w/pivot
    {
      DataType temp = data[pivot];
      data[pivot] = data[l];
      data[l] = temp;
      pivot = l;
      --r;
    }
    else // swap around the pivot
    {
      DataType temp = data[l];
      data[l] = data[r];
      data[r] = temp;
      ++l;
      --r;
    }
  }
}


#endif