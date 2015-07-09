
//Aysin Oruz
//Lab 8c 

#ifndef NODE
#define NODE
template<class DataType>
struct Node
{
  DataType data; // value in the node
  Node<DataType> *next; //pointer to the next node
};
#endif
 
#ifndef QUEUEDRIVER_H
#define QUEUEDRIVER_H
 
template<class DataType>
class Queue
{
private:
  Node<DataType> *front; // front of the queue
  Node<DataType> *end; // rear of the queue
  
public:
  //constructor, Destructor, copy constructor
  Queue();
  Queue(Queue<DataType>& );
  ~Queue();
  Queue<DataType> & operator = (const Queue<DataType>& );
 
  //Queue operations
  void push(const DataType&);
  bool pop(DataType&);
  bool isEmpty() const;
  void makeEmpty();
  bool peek(DataType&) const;
  
};
 
//constructor
template <class DataType>
Queue<DataType>::Queue()
{
  front = 0;
  end = 0;
}
 
//copy constructor
template <class DataType>
Queue<DataType>::Queue(Queue<DataType>& a)
:front(0), end(0)
{
  Node<DataType>* p;
  for (p = a.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if(end) end->next = node;
    else front = node;
    end = node;
  }
}
 
//Destructor
template <class DataType>
Queue<DataType>::~Queue()
{
  Node<DataType> *p;
  while (front)
  {
    p = front->next;
        delete front;
        front = p;
  }
}

//operator
template <class DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& a)
{
  if (this != &a)
  {
    Node<DataType>* p;
    
    // deallocate existing queue
    end = 0; // data member end pointer
    while (front)
    {
      p = front->next;
      delete front;
      front = p;
    }
    
    // build new queue
    for (p = a.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else front = node;
      end = node;
    } }
  return *this;
}

//push function
template <class DataType>
void Queue<DataType>::push(const DataType& parameter)
{
  Node<DataType> *node = new Node<DataType>;
  node->data = parameter;
  node->next = 0;
  if (end)
   end-> next = node;
  else
    front = node;
  end = node;
  
}
 
//pop function
template <class DataType>
bool Queue<DataType>::pop(DataType& parameter)
{
  if(0 == front) return false; // failed
  parameter = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if(front == 0) end = 0;
  return true; // success
}
 
template <class DataType>
bool Queue<DataType>::isEmpty() const {return 0 == front;}

//make empty function
template <class DataType>
void Queue<DataType>::makeEmpty()
{
  end = 0;
  Node<DataType>* p;
  while(front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}

//peek
template <class DataType>
bool Queue<DataType>::peek(DataType& parameter) const
{
  if(0 == front)
    return false; // failed
  parameter = front->data;
  return true; // success
  
}
#endif