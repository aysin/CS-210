//Lab 10b

#include <iostream>
#include "LinkedList.h"
 
using namespace std;
 
LinkedList<int> getElements();
float calcAverage(LinkedList<int> avnums);
void printNumbers(LinkedList<int> pNums);
void search(LinkedList<int> sNums);
 
 
int main()
{
  
  cout << "description: this program creates a linked list of integers and searches for a particular number and returns it's index in the list." << endl;
  LinkedList <int> nums(2);
  nums = getElements();
  float average = calcAverage(nums);
  cout << "The average is: " << average << endl;
  printNumbers(nums);
  search(nums);
  return 0;
}
 
LinkedList<int> getElements()
{
       
  LinkedList<int> numbers(2);
  int i = 0;
       
  cout << "Enter a positive integer: ";
  cin >> numbers[i];
  while (numbers[i] != -1)
  {
        i++;
        if (i == numbers.length())
          numbers.changeSize(i*2);
        cout << "Enter a positive integer (enter -1 to stop): ";
        cin >> numbers[i];
  }
       
  numbers.changeSize(i);
       
  return numbers;
}
 
float calcAverage(LinkedList<int> avnums)
{
  int sum = 0;
  for (int i = 0; i < avnums.length(); i++)
        sum += avnums[i];
  return sum/float(avnums.length());
}
 
void printNumbers(LinkedList<int> pNums)
{
  cout << "here are the printed elements in the array: " << endl;
  for(int i = 0; i < pNums.length(); i++)
  {
        cout << pNums[i] << " ";
  }
  cout << endl;
}
 
void search(LinkedList<int> sNums)
{
  int number;
  while (number != 0)
  {
        cout << "enter in a number to search for or [0] to quit: " << endl;
        cin >> number;
        int position = sNums.lsearch(number);
        cout << position << endl;
  }
  cout << "bye!" << endl;
}