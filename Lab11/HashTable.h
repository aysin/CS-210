//
//
//Lab 11a, HashTable.h Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <list>
#include <algorithm>
using namespace std;

#ifndef HashTable_h
#define HashTable_h

//#define CAPACITY = 1009; //initilize Capacity

template<class T, int CAPACITY>
class HashTable
{
public:
  HashTable(); //consturactor
  void insert (const T&); //insert function for value
  bool retrieve (T&); //retrieving value
  bool replace(T&);
  bool remove (T&); //removing values
  
  void clear(); //clearing table
  int size() const;
  
private:
  list<T> hTable[CAPACITY];
  int count;
  int currentIndex;
  int index;
  int wrappedIndex(const T&);
  typename list<T>::const_iterator it;
};

template<class T, int CAPACITY>
int HashTable<T, CAPACITY>::wrappedIndex(const T& parameter)
{
  //getting the W.I.
  index = parameter.hashCode();
  int wrappedIndex = index % CAPACITY;
  if (wrappedIndex < 0)
    wrappedIndex = wrappedIndex + CAPACITY;
  return wrappedIndex;
}
//consturactor
template<class T, int CAPACITY>
HashTable<T, CAPACITY>::HashTable()
{
  count = 0;
  currentIndex = -1;
}

//insert function for value
template<class T, int CAPACITY>
void HashTable<T, CAPACITY>::insert (const T& value)
{
  //getting the W.I.
  index = wrappedIndex(value);
  typename list<T>::iterator it;
  it = find(hTable[index].begin(), hTable[index].end(), value);
  if (it != hTable[index].end()) *it = value; // replace
  else {hTable[index].push_back(value); ++count;}
}

//retrieving value
template<class T, int CAPACITY>
bool HashTable<T, CAPACITY>::retrieve (T& a)
{
  //getting the W.I.
  index = wrappedIndex(a);
  
  //iterator for traversing values
  typename list<T>::iterator it;
  it = find(hTable[index].begin(), hTable[index].end(), a);
  if (it == hTable[index].end()) return false; // replace
  else a = *it;
  return true;
}

template<class T, int CAPACITY>
bool HashTable<T, CAPACITY>::replace(T& parameter)
{
  index = wrappedIndex(parameter);
  typename list<T>::iterator it;
  it = find(hTable[index].begin(), hTable[index].end(), parameter);
  
  if(it == hTable[index].end())
    return false; // cannot do
  else
    *it = parameter;
  return true;
  
}

//removing values
template<class T, int CAPACITY>
bool HashTable<T, CAPACITY>::remove (T& value)
{
  //getting the W.I.
  index = wrappedIndex(value);
  
  //iterator for traversing values
  typename list<T>::const_iterator it;
  
  it = find(hTable[index].begin(), hTable[index].end(), value);
  if (it == hTable[index].end()) return false;
  
  value = *it;
  hTable[index].erase(it);
  count--;
  return true;
}

//clearing table
template<class T, int CAPACITY>
void HashTable<T, CAPACITY>::clear()
{
  count = 0;
  currentIndex = -1;
  
  for (int i = 0; i < CAPACITY; i++)
    if (!hTable[i].empty())
      hTable[i].clear();
}

//Size track
template<class T, int CAPACITY>
int HashTable<T,CAPACITY>::size() const
{
  return count;
}


#endif

