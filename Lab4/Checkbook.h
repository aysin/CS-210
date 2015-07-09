//
//
//Lab 4b, CheckBook Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef Checkbook_H
#define Checkbook_H


template <class DataType>
class Checkbook 
{
public:
  Checkbook ();
  Checkbook (float iniBalance);
  DataType *getChecks();
  void setBalance (float amount);
  void deposit (float amount);
  bool writeCheck (const DataType& amount); // returns false/true
  float getBalance () const;
  float getLastIndex () const;

private:
  float balance;
  int size;
  int capacity;
  void doubleArray();
  DataType* checks;
  
};

template <class DataType>
Checkbook<DataType>::Checkbook() {}

template <class DataType>
Checkbook<DataType>::Checkbook (float iniBalance)
{
  balance = iniBalance;
  capacity = 2;
  size = 0;
  checks = new DataType[capacity];
}

template <class DataType>
bool Checkbook<DataType>::writeCheck (const DataType& amount)
{
  bool result;
  if (amount > balance)
  { result = false; }
  
  if (balance >= amount)
  {
    balance -= amount;
    doubleArray ();
    checks[size] = amount;
    size++;
    result = true;
  }
  return result;
}

template <class DataType>
void Checkbook<DataType>::deposit (float amount)
{ balance += amount; }

template <class DataType>
float Checkbook<DataType>::getBalance () const
{ return balance; }

template <class DataType>
float Checkbook<DataType>::getLastIndex () const
{ return size; }

template <class DataType>
void Checkbook<DataType>::doubleArray ()
{
  DataType* temp = new DataType[capacity * 2];
  for (int i = 0; i < capacity; i++)
    temp[i] = checks[i];
  
  delete [] checks;
  checks = temp;
  capacity *= 2; 

}

template <class DataType>
DataType *Checkbook<DataType>::getChecks ()
{
  DataType *checksCopy = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
  {
    checksCopy[i] = checks[i];
  }
  return checksCopy;
}

#endif

