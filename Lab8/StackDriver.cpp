//
//
//Lab 8a StackDriver.cpp
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include "Stack.h"
#include "Stack.h" //ifndef
using namespace std;
#include <cassert>

int main()
{
  cout << "\n\nLab 8a, Stack.h, StackDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply a Stack list.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
	Stack<int> s;

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
  cout << "\nTesting Not Empty Stack\n";
  cout << "StackList >> ";
  for (int i = 0; i < 4; i++)
  {
    s.push(list[i]);
    cout << i << ", ";
  }
  cout << "\nExpected result is >> Stack is Full!\n";
  assert(s.isEmpty() == 0);
  if (s.isEmpty() == 0)
    cout << "Actual result >> Stack is Full!\n";
  else
    cout << "Actual result >> Stack is Empty!\n\n";
  
  //Peek Function
  int stackList = 0;
  cout << "\nTesting Peek Function\n";
  cout << "Expected result at the top of the list >> 3\n";
  assert(s.peek(stackList) == 1);
  cout << "Actual result at the top of the list >> " << stackList << endl << endl;
  
  //Pop Function
  s.pop(stackList);
  cout << "Testing Pop Function\n";
  cout << "After popping last value (3)\n";
  cout << "Expected result at the top of the list >> 2\n";
  assert(s.peek(stackList) == 1);
  cout << "Actual result at the top of the list >> " << stackList << endl;
  
  //Clear the List
  s.makeEmpty();
  cout << "\nTesting to clear the Stack List\n";
  cout << "Expected result >> Empty\n";
  assert(s.isEmpty() == 1);
  if (s.isEmpty() == 1)
    cout << "Actual result >> Empty!\n";
  else
    cout << "Actual result >> Full!\n\n";
  
  //Push Function Test To Fill The Stack
  for (int i = 0; i < 4; i++)
  {
    s.push(list[i]);
  }
  
  // Const object copy testing, with assignment UPON declaration
  {
    const Stack<int> copy = s;
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
    int stackList = 0;
    cout << "\nTesting Peek Function\n";
    cout << "Expected result at the top of the list >> 3\n";
    assert(copy.peek(stackList) == 1);
    cout << "Actual result at the top of the list >> " << stackList << endl << endl;
 
  }
  
  // Const object copy testing, with assignment AFTER declaration
  {
    Stack<int> copy; copy = s;
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
    int stackList = 0;
    cout << "\nTesting Peek Function\n";
    cout << "Expected result at the top of the list >> 3\n";
    assert(copy.peek(stackList) == 1);
    cout << "Actual result at the top of the list >> " << stackList << endl;
    
    //Pop Function
    copy.pop(stackList);
    cout << "\nTesting Pop Function\n";
    cout << "After popping last value (3)\n";
    cout << "Expected result at the top of the list >> 2\n";
    assert(copy.peek(stackList) == 1);
    cout << "Actual result at the top of the list >> " << stackList << endl;
    
    //Clear the List
    copy.makeEmpty();
    cout << "\nTesting to clear the Stack List\n";
    cout << "Expected result >> Empty\n";
    assert(copy.isEmpty() == 1);
    if (copy.isEmpty() == 1)
      cout << "Actual result >> Empty!\n";
    else
      cout << "Actual result >> Full!\n\n";
    
    //Push new value when Stack is Empty
    cout << "\nPushing new value to Empty List\n";
    cout << "Expected result >> 25 \n";
    copy.push(25); copy.peek(stackList);
    cout << "Actual result >> " << stackList << endl;
  }

  //Clear the List
  s.makeEmpty();
  cout << "\nClearing the Stack List\n";
  cout << "Expected result >> Empty\n";
  assert(s.isEmpty() == 1);
  if (s.isEmpty() == 1)
    cout << "Actual result >> Empty!\n";
  else
    cout << "Actual result >> Full!\n\n";
  
  
}