#ifndef _DYN_ARRAY_
#define _DYN_ARRAY_

#include <iostream>
#include <algorithm>

template <typename T>
class DynArray
{
public:
   DynArray();
   DynArray(int size);
   DynArray(int size, const T& value);
   DynArray(std::initializer_list<T> li);
   DynArray(const DynArray& da);
   DynArray& operator = (const DynArray& da);
   DynArray(DynArray&& da);
   DynArray& operator = (DynArray&& da);
   ~DynArray();

   void push_back(const T& value);
   void pop_back();
   void push_front(const T& value);
   void pop_front();
   void remove(int index);
   void insert_after(int index, const T& value);
   void insert_before(int index, const T& value);
   void resize(int size);
   void reverse();

   T* front();
   T* back();
   bool empty() const;
   size_t size() const;
   void clear();
   void print() const;
   void sort();
private:
   size_t m_size;
   T* m_data;
};

#include "dyn_array.cpp"
#endif