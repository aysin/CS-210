//Aysin Oruz
//Lab 10A Linklist.h
//Terminal and JNote, Xcode

#ifndef NODE_H
#define NODE_H

template <class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};
#endif

#ifndef LinkList_h
#define LinkList_h

template<class DataType>
class LinkedList
{
public:
  LinkedList(); //Default Constructor
  LinkedList(const LinkedList<DataType>& ); //Copy Constructor
  ~LinkedList();  //Destructor
  LinkedList<DataType>& operator=(const LinkedList<DataType>& ); //Assignmet Operator
  
  DataType& operator[] (const DataType& ); //Operator[]
  int length() const;
  int capacity;
  int currentIndex;
  
  void insert(const DataType& ); // O(1) - Index
  bool first(DataType& ); // O(1) - GetFirst
  bool getNext(DataType& ); // O(1) - GetNext
  bool find(const DataType&); // -Find
  bool retrieve(DataType& ); // O(n) -Retrieve
  bool replace(const DataType& ); // O(1) -Replace
  bool remove(DataType& ); // O(n) Remove
  bool isEmpty() const; // O(1) -isEmpty
  void makeEmpty(); // O(n) -MakeEMpty
  
private:
  Node<DataType>* start; // initailly zero
  Node<DataType>* current; // possibly zero
  DataType dummy;
  
};

//Default Constructor
template <class DataType>
LinkedList<DataType>::LinkedList()
: capacity(0), currentIndex(-1), start(0), current(0){}


//Copy Constructor
template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a)
: start(0), current(0)
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  capacity = a.capacity;
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p == a.current) current = node;
  }
}

//Destructor
template <class DataType>
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

// Operator =
template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  if (this != &a)
  {
    current = 0;
    currentIndex =-1;
    int tempC = a.capacity;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }
    for (p = a.start; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      if (p == a.current) current = node;
    }
    capacity = tempC;
  }
  return *this;
}

//Operator []
template <class DataType>
DataType& LinkedList<DataType>::operator[](const DataType& index)
{
  if (!start || index < 0 || index >= capacity)
    return dummy;
  
  else if (index == 0)
  {
    currentIndex = 0;
    current= start;
    return current->data;
  }
  
  if( index - currentIndex == 1)
  {
    current = current->next;
    currentIndex++;
    return  current->data;
    if (!current)
    {
      currentIndex = -1;
      return dummy;
    }
  }
  else
  {
    currentIndex = -1;
    current = start;
    for(; current; current = current->next)
    {
      currentIndex++;
      if(currentIndex == index)
        break;
    }
  }
  return current->data;
}


//Const Length
template <class DataType>
int LinkedList<DataType>::length() const
{
  return capacity;
}

//insert function
template <class DataType>
void LinkedList<DataType>::insert(const DataType& parameter) // O(1)
{
  current = 0; currentIndex = -1;
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
  capacity++;
}

//Get First Function
template <class DataType>
bool LinkedList<DataType>::first(DataType& parameter) // O(1)
{
  if (!start) return false;
  parameter = start->data;
  current = start;
  currentIndex = 0;
  return true;
}

//GetNExt
template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter) // O(1)
{
  if (!current) return false;
  current = current->next;
  if (!current) return false;
  parameter = current->data;
  currentIndex++;
  return true;
}
//Find
template<class DataType>
bool LinkedList<DataType>::find(const DataType& parameter)
{
  DataType temp;
  currentIndex = -1;
  if (first(temp)) do
  {
    if (parameter == temp)
      return true;
  } while (getNext(temp));
  return false;
}

//REtrieve
template<class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) // O(n)
{
  if (!find(parameter)) return false;
  parameter = current->data; // set in find
  return true;
}

//Replace
template<class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter) // O(1)
{
  if (!current) return false;
  current->data = parameter;
  return true;
}

//Remove
template<class DataType>
bool LinkedList<DataType>::remove(DataType& parameter) // O(n)
{
  // find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p; prev = p, p = p->next)
    if (p->data == parameter)
      break;
  
  // deallocate node here
  if (!p) return false; // no match
  if (prev) prev->next = p->next; else start = p->next;
  if (p == current)
  {
    current = current->next;
    currentIndex++;
  }
  parameter = p->data;
  delete p; capacity--;
  return true;
}

//IsEmpty
template<class DataType>
bool LinkedList<DataType>::isEmpty() const // O(1)
{
  return start == 0;
}

//MakeEmpty
template<class DataType>
void LinkedList<DataType>::makeEmpty() // O(n)
{
  while (start)
  {
    current = start->next;
    currentIndex = -1;
    delete start;
    start = current;
  }
}


#endif

