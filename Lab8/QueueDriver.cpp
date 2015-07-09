//
//
//Lab 8a QueueDriver.cpp
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include "Queue.h"
#include "Queue.h" //ifndef
using namespace std;
#include <cassert>

int main()
{
  cout << "\n\nLab 8a, Queue.h, QueueDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply a Queue list.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
	Queue<int> s;
  
  //isEmpty Function Test
  cout << "\nTesting isEmpty() Function\n";
  cout << "Expected result >> Empty\n";
  assert(s.isEmpty() == 1);
  if (s.isEmpty() == 1)
    cout << "Actual result >> Empty!\n";
  else
    cout << "Actual result >> Full!\n\n";
  
  //Push Function Test
  int list[4] = {0, 1, 2, 3};
  cout << "\nTesting Not Empty Queue\n";
  cout << "QueueList >> ";
  for (int i = 0; i < 4; i++)
  {
    s.push(list[i]);
    cout << i << ", ";
  }
  cout << "\nExpected result is >> Queue is Full!\n";
  assert(s.isEmpty() == 0);
  if (s.isEmpty() == 0)
    cout << "Actual result >> Queue is Full!\n";
  else
    cout << "Actual result >> Queue is Empty!\n\n";
  
  //Peek Function
  int QueueList = 0;
  cout << "\nTesting Peek Function\n";
  cout << "Expected result at the top of the list >> 0\n";
  assert(s.peek(QueueList) == 1);
  cout << "Actual result at the top of the list >> " << QueueList << endl << endl;
  
  //Pop Function
  s.pop(QueueList);
  cout << "Testing Pop Function\n";
  cout << "After popping last value (0)\n";
  cout << "Expected result at the top of the list >> 1 \n";
  assert(s.peek(QueueList) == 1);
  cout << "Actual result at the top of the list >> " << QueueList << endl;
  
  //Clear the List
  s.makeEmpty();
  cout << "\nTesting to clear the Queue List\n";
  cout << "Expected result >> Empty\n";
  assert(s.isEmpty() == 1);
  if (s.isEmpty() == 1)
    cout << "Actual result >> Empty!\n";
  else
    cout << "Actual result >> Full!\n\n";
  
  //Push Function Test To Fill The Queue
  for (int i = 0; i < 4; i++)
  {
    s.push(list[i]);
  }
  
  // Const object copy testing, with assignment UPON declaration
  {
    const Queue<int> copy = s;
    cout << "\nConst object copy testing, with assignment UPON declaration\n";
    
    //isEmpty Function Test
    cout << "\nTesting isEmpty() Function\n";
    cout << "Expected result >> Full\n";
    assert(copy.isEmpty() == 0);
    if (copy.isEmpty() == 0)
      cout << "Actual result >> Full!\n";
    else
      cout << "Actual result >> Empty!\n\n";
    
    //Peek Function
    int QueueList = 0;
    cout << "\nTesting Peek Function\n";
    cout << "Expected result at the front of the list >> 0\n";
    assert(copy.peek(QueueList) == 1);
    cout << "Actual result at the front of the list >> " << QueueList << endl << endl;
    
  }
  
  // Const object copy testing, with assignment AFTER declaration
  {
    Queue<int> copy; copy = s;
    cout << "Const object copy testing, with assignment AFTER declaration\n\n";
    
    //isEmpty Function Test
    cout << "Testing isEmpty() Function\n";
    cout << "Expected result >> Full\n";
    assert(copy.isEmpty() == 0);
    if (copy.isEmpty() == 0)
      cout << "Actual result >> Full!\n";
    else
      cout << "Actual result >> Empty!\n\n";
    
    //Peek Function
    int QueueList = 0;
    cout << "\nTesting Peek Function\n";
    cout << "Expected result at the top of the list >> 0\n";
    assert(copy.peek(QueueList) == 1);
    cout << "Actual result at the top of the list >> " << QueueList << endl;
    
    //Pop Function
    copy.pop(QueueList);
    cout << "\nTesting Pop Function\n";
    cout << "After popping last value (0)\n";
    cout << "Expected result at the front of the list >> 1\n";
    assert(copy.peek(QueueList) == 1);
    cout << "Actual result at the front of the list >> " << QueueList << endl;
    
    //Clear the List
    copy.makeEmpty();
    cout << "\nTesting to clear the Queue List\n";
    cout << "Expected result >> Empty\n";
    assert(copy.isEmpty() == 1);
    if (copy.isEmpty() == 1)
      cout << "Actual result >> Empty!\n";
    else
      cout << "Actual result >> Full!\n\n";
    
    //Push new value when Queue is Empty
    cout << "\nPushing new value to Empty List\n";
    cout << "Expected result >> 25 \n";
    copy.push(25); copy.peek(QueueList);
    cout << "Actual result >> " << QueueList << endl;
  }
  
  //Clear the List
  s.makeEmpty();
  cout << "\nClearing the Queue List\n";
  cout << "Expected result >> Empty\n";
  assert(s.isEmpty() == 1);
  if (s.isEmpty() == 1)
    cout << "Actual result >> Empty!\n";
  else
    cout << "Actual result >> Full!\n\n";
  
  
}