//Aysin ORuz
//Lab 12A
//Terminal, Xcode, Jnote

#include <iostream>
using namespace std;
#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h" //ifnef testing


int main()
{
  cout << "\n\nLab 12a, PriorityQueueDriver.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply our PriorityQueue file.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  PriorityQueue<int> PQlist;
  
  cout << "Building a Priority Queue\n\n";
  cout << "1-)Testing getsize function when queue is empty\n";
  cout << "Expected  >> 0\n";
  assert(PQlist.getSize() == 0);
  cout << "Actual >> " << PQlist.getSize() << endl;
  
  cout << "\n2-)Testing enqueue function by adding new values\n";
  for (int i = 0; i < 8; i++)
    PQlist.enqueue(i);
  assert(PQlist.getSize());
  cout << "Expected >> 8\n";
  cout << "Actual >> " << PQlist.getSize() << endl;
  
  cout << "\n3-) Testing Dequeue Function by removing largest value\n";
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  
  cout << "\n4-)Testing getsize function after dequeue\n";
  cout << "Expected  >> 7\n";
  assert(PQlist.getSize() == 7);
  cout << "Actual >> " << PQlist.getSize() << endl;
  
  cout << "\n5-) Testing Dequeue Function by removing largest value\n";
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  
  cout << "\n6-)Testing getsize function after dequeue\n";
  cout << "Expected  >> 6\n";
  assert(PQlist.getSize() == 6);
  cout << "Actual >> " << PQlist.getSize() << endl;
  
  cout << "\n7-) Testing Dequeue Function by removing largest values\n";
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  cout << "Removed value >> " << PQlist.dequeue() << endl;
  
  cout << "\n8-)Testing getsize function after dequeue\n";
  cout << "Expected  >> 0\n";
  assert(PQlist.getSize() == 0);
  cout << "Actual >> " << PQlist.getSize() << endl;
  
  cout << "\nValues added back to PQ\n";
  for (int i = 0; i < 8; i++)
    PQlist.enqueue(i);
  assert(PQlist.getSize());
  //Const object copy testing with assignment UPON declaration
  {
    const PriorityQueue<int> copy= PQlist;
    cout << "\nCONST object copy testing with assignment UPON declaration\n";
    cout << "\nTesting getsize()\nExpected >> 8\n";
    cout << "Actual >> " << copy.getSize() << endl;
    assert(copy.getSize() == 8);
  }
  
  //object copy testing with assignment UPON declaration
  {
    PriorityQueue<int> copy = PQlist;
    cout << "\nobject copy testing with assignment UPON declaration\n";
    cout << "\nTesting getsize()\nExpected >> 8\n";
    cout << "Actual >> " << copy.getSize() << endl;
    assert(copy.getSize() == 8);
    
    cout << "\nDequeue all the values in the PQ\n";
    assert(copy.dequeue() == 7); assert(copy.dequeue() == 6);
    assert(copy.dequeue() == 5); assert(copy.dequeue() == 4);
    assert(copy.dequeue() == 3); assert(copy.dequeue() == 2);
    assert(copy.dequeue() == 1); assert(copy.dequeue() == 0);
    
    cout << "\nGetsize() after dequeue\n";
    cout << "Expected >> 0\n";
    cout << "Actual >> " << copy.getSize() << endl;
  }
  // object copy testing with assignment Afterdeclaration
  {
    PriorityQueue<int> copy; copy = PQlist;
    cout << "\nobject copy testing with assignment AFTER declaration\n";
    cout << "\nTesting getsize()\nExpected >> 8\n";
    cout << "Actual >> " << copy.getSize() << endl;
    assert(copy.getSize() == 8);
    
    cout << "\nDequeue all the values in the PQ\n";
    assert(copy.dequeue() == 7); assert(copy.dequeue() == 6);
    assert(copy.dequeue() == 5); assert(copy.dequeue() == 4);
    assert(copy.dequeue() == 3); assert(copy.dequeue() == 2);
    assert(copy.dequeue() == 1); assert(copy.dequeue() == 0);
    
    cout << "\nGetsize() after dequeue\n";
    cout << "Expected >> 0\n";
    cout << "Actual >> " << copy.getSize() << endl;
  }
 
  
  cout << "\nDequeue() - Empty the list\n";
  for (int i = 0; i < 8; i++)
    PQlist.dequeue();
  assert(PQlist.getSize() == 0);
  cout << "List is empty!\n";

}