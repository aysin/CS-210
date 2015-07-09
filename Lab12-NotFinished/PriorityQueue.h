//Aysin Oruz
//JNote, Xcode, Terminal
//Lab 12 a - H File

#ifndef PriorityQueue_h
#define PriorityQueue_h


template<class T>
class PriorityQueue
{
public:
  PriorityQueue();
  
  //dynamic array memory arrangmnt
  ~PriorityQueue();
  PriorityQueue(const PriorityQueue<T>& );
  PriorityQueue<T>& operator=(const PriorityQueue<T>& a);
  
  T dequeue();
  int getSize() const {return size;}
  void enqueue(const T&);
  // void changeCapacity (int newCap);
  
private:
  T* data;
  int size;
  int capacity;
};

template<class T>
PriorityQueue<T>::PriorityQueue()
: size(0), capacity(2)
{ data = new T[capacity];}

//copy constructor
template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& a)
:capacity(a.capacity), size(a.size)
{
  data = new T[capacity];
  for (int i = 0; i < size; i++)
    data[i] = a.data[i];
}

//destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
  delete [] data;
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& a)
{
  if (this != &a)
  {
    delete [] data;
    data = 0;
    size = a.size;
    capacity = a.capacity;
    data = new T[capacity];
    for(int i = 0; i <= size; i++)
      data[i] = a.data[i];
  }
  return *this;
}

/*template<class T>
 void PriorityQueue<T>::changeCapacity(int newCap)
 {
 T* newData = new T[newCap];
 int limit = newCap > capacity ? capacity : newCap;
 for (int i = 0; i < limit; i++)
 newData[i] = data[i];
 delete [] data;
 data = newData;
 capacity = newCap;
 
 }*/

template<class T>
void PriorityQueue<T>::enqueue(const T& number)
{
  T temp;
  int index = size;
  if (index >= capacity)
  {
    T* newPQ;
    int newCap = 2 * capacity;
    newPQ = new T[newCap];
    for(int i = 0; i < capacity; i++)
      newPQ[i] = data[i];
    delete [] data;
    data = newPQ;
    capacity = newCap;
  }
  data[index] = number;
  
  while(true)
  {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0) break;
    if (data[parentIndex] >= data[index]) break;
    temp = data[parentIndex];
    data[parentIndex] = data[index];
    data[index] = temp;
    index = parentIndex;
  }
  size++;
}

template <class T>
T PriorityQueue<T>::dequeue()
{
  T dataPQ;
  T temp;
  dataPQ = data[0];
  int index = 0;
  
  while(true)
  {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if(leftChild >= size) break;
    if(leftChild == size - 1 || data[leftChild] >= data[rightChild])
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
  
  if(size > 2 && size < capacity / 4)
  {
    int newCapacity = capacity / 2;
    T* newPQ;
    newPQ= new T[newCapacity];
    for(int i = 0; i <= size; i++)
      newPQ[i] = data[i];
    delete [] data;
    data = newPQ;
    capacity = newCapacity;
  }
  data[index] = data[size];
  
  while(true)
  {
    int parentIndex = (index + 1) / 2 - 1;
    if(parentIndex < 0) break;
    if(data[parentIndex] >= data[index]) break;
    temp = data[parentIndex];
    data[parentIndex] = data[index];
    data[index] = temp;
    index = parentIndex;
  }
  return dataPQ;
}


#endif