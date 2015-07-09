//
//
//Lab 14a,MySortableArray.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "SortableArray.h"


SortableArray<int> getData();
SortableArray<int> sort(SortableArray<int> numbers);
float calcAverage(SortableArray<int> avnums);
void print(SortableArray<int> numbers);
void search(SortableArray<int> numbers);
void bsearch(SortableArray<int> numbers);

int main()
{
  cout << "\n\nLab //Lab 14a,MySortableArray.cpp Program\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description:  The purpose of this lab is for you to ";
  cout << "write a templated class, complete with dynamic memory management.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  SortableArray<int> nums(2); nums = getData();
  int average = calcAverage(nums);
  cout << "The average is >> " << average << endl;
  print(nums);    //unsorted list
  search(nums);
  nums = sort(nums);  //linear search
  bsearch(nums);   //binary search
}

void bsearch(SortableArray<int> numbers)
{
  int results;
  int input = 0;
  string buf;
  cout << "\nBINARY SEARCH (To QUIT Press -1)" << endl;
  
  while (input != -1)
  {
    cout << "Enter the number you want to search >> ";
    cin >> buf; input = atoi(buf.c_str());
    results = numbers.bsearch(input);
    
    if (results != -1)
      cout << "The index for the data you searched is >> " << results << endl;
    else
      cout << input << " is not in this array!" << endl << endl;
  }
  cout << "Program finished succesfully.." << endl;
}


SortableArray<int> sort(SortableArray<int> numbers)
{
  cout << endl;
  cout << "Binary search will start after your entries!\nArray Length is >> [0," << numbers.length() - 1 << "]" << endl;
  cout << "After entries of max and min to QUIT Press -1." << endl;
  
  int min = 0;
  int max = 0;
  string buf;
  while (min != -1 && max != -1)
  {
    cout << "Enter the array's minimum digit >> ";
    cin >> buf; min = atoi(buf.c_str());
    if( min == -1 )
      break;
    cout << "Enter the array's maximum digit >> ";
    cin >> buf; max = atoi(buf.c_str());
    if( max == -1 )
      break;
    
    if( min >= 0 && min <= numbers.length() - 1 && max >= 0 && max <= numbers.length() - 1 )
    {
      numbers.sort(min, max);
      print(numbers);
    }
    else
    {
      cout << "This is not the array length" << endl;
    }
    cout << endl;
  }
  return numbers;
  
}


SortableArray<int> getData()
{
  SortableArray<int> numbers(2);
  int i = 0;
  string buf;
  cout << "\nEnter a positive integer >> ";
  cin >> buf; numbers[i] = atoi(buf.c_str());
  while (numbers[i] != -1)
  {
    i++;
    if (i == numbers.length())
    {
      numbers.changeSize(i * 2);
    }
    cout << "Enter a positive integer (To QUIT Press -1) >> ";
    cin >> numbers[i];
  }
  numbers.changeSize(i);
  return numbers;
}

float calcAverage(SortableArray<int> avnums)
{
  int sum = 0;
  for (int i = 0; i < avnums.length(); i++)
  {
    sum += avnums[i];
  }
  
  return sum /(avnums.length());
}

void print(SortableArray<int> numbers)
{
  cout << "Array  numbers >> ";
  for (int i = 0; i < numbers.length() - 1; i++) {
    cout << numbers[i] << ",";
  }
  cout << numbers[numbers.length() - 1]; //print last element
  cout << endl;
}

void search(SortableArray<int> numbers)
{
  cout << "\nLINEAR SEARCH." << endl;
  cout << "To QUIT and to END the search press -1." << endl;
  int results;
  int input = 0;
  string buf;
  while (input != -1)
  {
    cout << "Enter the number you want to search >> ";
    cin >> buf; input = atoi(buf.c_str());
    results = numbers.lsearch(input);
    if (results != -1)
      cout << "The index for the data you searched is >> " << results << endl;
    else
      cout << input << " is not in this array!" << endl << endl;
  }
  cout << "Linear Search finished succesfully.." << endl;
}