// Lab 11a:  HashTable.h

 
#ifndef HashTable_h
#define HashTable_h
 
 
#define HASHTABLE_CAPACITY 1009
 
 
#include <list>   //used for hash table
#include <algorithm> //used for find
 
 
template <class DataType>
class HashTable
{
public:
        HashTable();
       
        int size() const { return count; }          //getter
       
        bool insert( const DataType& parameter, int DI );
       
        bool replace( const DataType& parameter, int DI );
        bool remove( const DataType& parameter, int DI );
        bool retrieve( DataType& parameter, int DI );
       
        void clear();
       
        HashTable<DataType>& operator =(const HashTable<DataType>& right);
       
private:
        void wrappedIndex( int index );
       
        list<DataType> table[HASHTABLE_CAPACITY];
        typename list<DataType>::iterator it;
       
       
        int current;
        int wIndex;
       
        int count;
};
 
 
template <class DataType>
HashTable<DataType>& HashTable<DataType>::operator =(const HashTable<DataType> & right)
{
    if (this == &right)
    {
        return *this;
    }
       
    this->current = right.current;
    this->wIndex = right.wIndex;
    this->count = right.count;
       
       
    for( int i = 0; i < HASHTABLE_CAPACITY; i++ )
    {
        this->table[i] = right.table[i];
    }
       
    return *this;
}
 
template<class DataType>
HashTable<DataType>::HashTable()
:count(0),current(-1),wIndex(0){}
 
template <class DataType>
bool HashTable<DataType>::insert( const DataType& parameter, int DI )
{
       
       
       
    wrappedIndex( DI );
       
    it = find(table[wIndex].begin(), table[wIndex].end(), parameter);
       
    if (it != table[wIndex].end())
    {
        *it = parameter; // replace
        return false;
    }
    else
    {
        if (count >= 800 ) //requirement of lab11a
        {
            return false;
        }
        table[wIndex].push_back(parameter);
        ++count;
        return true;
    }
}
 
 
template<class DataType>
void HashTable<DataType>::clear()
{
    for(int i=0;i<HASHTABLE_CAPACITY;i++){
        table[i].clear();
    }
    current = -1;
    count = 0;
    wIndex = 0;
}
 
 
 
template <class DataType>
bool HashTable<DataType>::remove( const DataType& parameter, int DI )
{
    wrappedIndex( DI );
       
    it = find(table[wIndex].begin(), table[wIndex].end(), parameter);
       
    if (it == table[wIndex].end()) return false;
    else
    {
        table[wIndex].erase(it);
        --count;
        return true;
    }
    //else this thing does not exist...
}
 
template <class DataType>
bool HashTable<DataType>::replace( const DataType& parameter, int DI )
{
    wrappedIndex( DI );
       
    it = find(table[wIndex].begin(), table[wIndex].end(), parameter);
       
    if (it == table[wIndex].end()) return false;
    else
    {
        *it = parameter;
        return true;
    }
    //else this thing does not exist...
}
 
 
template <class DataType>
bool HashTable<DataType>::retrieve( DataType& parameter, int DI )
{
    wrappedIndex( DI );
       
    it = find(table[wIndex].begin(), table[wIndex].end(), parameter);
       
    if (it == table[wIndex].end()) return false;
    else
    {
        parameter = *it;
        current = wIndex;
        return true;
    }
}
 
 
template <class DataType>
void HashTable<DataType>::wrappedIndex( int index )
{
    if( index > HASHTABLE_CAPACITY )
    {
        wIndex =  index % HASHTABLE_CAPACITY;
    }
    else if(  index < 0 )
    {
               
        wIndex =  index;
        while( wIndex < 0 )
            wIndex += HASHTABLE_CAPACITY;
               
        wIndex = wIndex % HASHTABLE_CAPACITY;
    }
    else
    {
        wIndex =  index;
    }
}
 
#endif