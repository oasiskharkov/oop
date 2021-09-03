#ifdef _DYN_ARRAY_

template<typename T>
DynArray<T>::DynArray() :
   m_size{ 0 },
   m_data{ nullptr }
{

}

template<typename T>
DynArray<T>::DynArray(int size) :
   m_size{ (size_t)size }
{
   if (size < 0)
   {
      throw std::logic_error("Incorrect array size.");
   }
   m_data = new T[m_size];
}

template<typename T>
DynArray<T>::DynArray(int size, const T& value) :
   m_size{ (size_t)size }
{
   if (size < 0)
   {
      throw std::logic_error("Incorrect array size.");
   }
   m_data = new T[m_size];
   for (size_t i = 0; i < m_size; ++i)
   {
      m_data[i] = value;
   }
}

template<typename T>
DynArray<T>::DynArray(std::initializer_list<T> list) :
   m_size{list.size()},
   m_data{new T[m_size]}
{
   size_t i = 0;
   for (const auto& l : list)
   {
      m_data[i++] = l;
   }
}

template<typename T>
DynArray<T>::DynArray(const DynArray& da)
{
   m_size = da.m_size;
   m_data = new T[m_size];
   for (size_t i = 0; i < m_size; ++i)
   {
      m_data[i] = da.m_data[i];
   }
}

template<typename T>
DynArray<T>& DynArray<T>::operator = (const DynArray& da)
{
   if (&da != this)
   {
      delete[] m_data;
      m_size = da.m_size;
      m_data = new T[m_size];
      for (size_t i = 0; i < m_size; ++i)
      {
         m_data[i] = da.m_data[i];
      }
   }
   return *this;
}

template<typename T>
DynArray<T>::DynArray(DynArray&& da)
{
   m_size = da.m_size;
   m_data = da.m_data;
   da.m_size = 0;
   da.m_data = nullptr;
}

template<typename T>
DynArray<T>& DynArray<T>::operator = (DynArray&& da)
{
   delete[] m_data;
   m_size = da.m_size;
   m_data = da.m_data;
   da.m_size = 0;
   da.m_data = nullptr;
   return *this;
}

template<typename T>
DynArray<T>::~DynArray()
{
   clear();
}

template<typename T>
T& DynArray<T>::operator [] (int index)
{
   if (index < 0 or index >= (int)m_size)
   {
      throw std::logic_error("Index is out of bounds.");
   }
   return m_data[size_t(index)];
}

template<typename T>
void DynArray<T>::push_back(const T& value)
{
   T* data = new T[m_size + 1];
   for (size_t i = 0; i < m_size; ++i)
   {
      data[i] = m_data[i];
   }
   data[m_size++] = value;
   delete[] m_data;
   m_data = data;
}

template<typename T>
void DynArray<T>::pop_back()
{
   if (!m_size)
   {
      std::cout << "DynArray is empty." << std::endl;
      return;
   }
   T* data = new T[--m_size];
   for (size_t i = 0; i < m_size; ++i)
   {
      data[i] = m_data[i];
   }
   delete[] m_data;
   m_data = data;
}

template<typename T>
void DynArray<T>::push_front(const T& value)
{
   T* data = new T[m_size + 1];
   for (size_t i = 0; i < m_size; ++i)
   {
      data[i + 1] = m_data[i];
   }
   data[0] = value;
   m_size++;
   delete[] m_data;
   m_data = data;
}

template<typename T>
void DynArray<T>::pop_front()
{
   if (!m_size)
   {
      std::cout << "DynArray is empty." << std::endl;
      return;
   }

   T* data = new T[m_size - 1];
   for (size_t i = 1; i < m_size; ++i)
   {
      data[i - 1] = m_data[i];
   }
   m_size--;
   delete[] m_data;
   m_data = data;
}

template<typename T>
void DynArray<T>::remove(int index)
{
   if (index < 0 or index >= (int)m_size)
   {
      std::cout << "Index is out of bounds." << std::endl;
      return;
   }

   T* data = new T[m_size - 1];
   for (size_t i = 0; i < (size_t)index; ++i)
   {
      data[i] = m_data[i];
   }

   for (size_t i = m_size - 1; i > (size_t)index; --i)
   {
      data[i - 1] = m_data[i];
   }
   m_size--;
   delete[] m_data;
   m_data = data;
}

template<typename T>
void DynArray<T>::reverse()
{
   for (size_t i = 0; i < m_size - i - 1; ++i)
   {
      std::swap(m_data[i], m_data[m_size - i - 1]);
   }
}

template<typename T>
void DynArray<T>::insert_after(int index, const T& value)
{
   if (index < 0 or index >= (int)m_size)
   {
      throw std::logic_error("Index is out of bounds.");
   }

   if ((size_t)index == m_size - 1)
   {
      push_back(value);
   }
   else
   {
      T* data = new T[m_size + 1];
      for (size_t i = 0; i <= (size_t)index; ++i)
      {
         data[i] = m_data[i];
      }
      data[index + 1] = value;
      for (size_t i = index + 2; i < m_size + 1; ++i)
      {
         data[i] = m_data[i - 1];
      }
      m_size++;
      delete [] m_data;
      m_data = data;
   }
}

template<typename T>
void DynArray<T>::insert_before(int index, const T& value)
{
   if (index < 0 or index >= (int)m_size)
   {
      throw std::logic_error("Index is out of bounds.");
   }

   if ((size_t)index == 0)
   {
      push_front(value);
   }
   else
   {
      T* data = new T[m_size + 1];
      for (size_t i = 0; i < (size_t)index; ++i)
      {
         data[i] = m_data[i];
      }
      data[index] = value;
      for (size_t i = index; i < m_size; ++i)
      {
         data[i + 1] = m_data[i];
      }
      m_size++;
      delete[] m_data;
      m_data = data;
   }
}

template<typename T>
void DynArray<T>::resize(int size)
{
   if (size < 0)
   {
      throw std::logic_error("Incorrect array size.");
   }
   else if ( size == 0)
   {
      clear();
   }
   else
   {
      T* data = new T[size];
      size_t newSize = (size_t)size <= m_size ? (size_t)size : m_size;
      for (size_t i = 0; i < newSize; ++i)
      {
         data[i] = m_data[i];
      }
      delete[] m_data;
      m_data = data;
      m_size = size;
   }
}


template<typename T>
bool DynArray<T>::empty() const
{
   return m_size == 0;
}

template<typename T>
T* DynArray<T>::front()
{
   if (m_size)
   {
      return &m_data[0];
   }
   return nullptr;
}

template<typename T>
T* DynArray<T>::back()
{
   if (m_size)
   {
      return &m_data[m_size];
   }
   return nullptr;
}

template<typename T>
size_t DynArray<T>::size() const
{
   return m_size;
}

template<typename T>
void DynArray<T>::clear()
{
   m_size = 0;
   delete[] m_data;
   m_data = nullptr;
}

template<typename T>
void DynArray<T>::print() const
{
   if (!m_size)
   {
      std::cout << "DynArray is empty." << std::endl;
      return;
   }

   for (size_t i = 0; i < m_size; ++i)
   {
      std::cout << m_data[i] << ' ';
   }
   std::cout << std::endl;
}

template<typename T>
void DynArray<T>::sort()
{
   if (m_size)
   {
      std::sort(&m_data[0], &m_data[m_size]);
   }
}

#endif