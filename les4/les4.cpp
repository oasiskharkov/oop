#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>

#include "dyn_array.h"

constexpr int size = 50;

DynArray<int> getEmptyDynArray()
{
   DynArray<int> da;
   return da;
}

int main()
{
   // ========== TASK #1 ==========
   DynArray<int> da{ 4, 1, 5, 2, 3, 7, 6, 8, 10, 9 };
   da.print();
   da.sort();
   da.print();
   std::sort(da.front(), da.back(), std::greater<int>());
   da.print();
   da.push_back(11);
   da.push_front(12);
   da.print();
   da.pop_back();
   da.pop_front();
   da.print();
   da.remove(9);
   da.remove(0);
   da.remove(3);
   da.print();
   da.resize(3);
   da.print();
   da.reverse();
   da.print();
   da.insert_after(0, 10);
   da.insert_after(3, 11);
   da.insert_after(1, 12);
   da.print();
   da.insert_before(0, 20);
   da.insert_before(6, 30);
   da.insert_before(2, 40);
   da.print();
   std::cout << da[3] << std::endl;
   da[3] = 100;
   da.print();
   std::cout << da.size() << std::endl;
   da.clear();
   std::cout << da.size() << std::endl;
   if (da.empty())
   {
      std::cout << "Dyn array is empty" << std::endl;
   }

   DynArray<int> da1 = da;
   da = getEmptyDynArray();
   DynArray<int> da2(10);
   DynArray<int> da3(5, 4);
   da1 = da2 = da3;
   da2 = DynArray<int>(3, 10);


   // ========== TASK #2 ==========
   std::random_device rd;
   std::mt19937 mt(rd());
   std::uniform_int_distribution<unsigned> dist(0, size);

   auto begin1 = std::chrono::steady_clock::now();

   std::vector<unsigned> values(size);
   for (auto& v : values)
   {
      v = dist(mt);
   }
   std::sort(std::begin(values), std::end(values));
   auto it = std::unique(std::begin(values), std::end(values));
   values.resize(std::distance(values.begin(), it));

   std::cout << "Unique elements count: " << values.size() << std::endl;

   auto end1 = std::chrono::steady_clock::now();
   auto ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
   std::cout << "Total time: " << ns1.count() << "ns" << std::endl;

   values.clear();

   auto begin2 = std::chrono::steady_clock::now();
   values.resize(size);
   std::set<int> uniques;
   for (auto& v : values)
   {
      v = dist(mt);
      uniques.insert(v);
   }
   std::cout << "Unique elements count: " << uniques.size() << std::endl;

   auto end2 = std::chrono::steady_clock::now();
   auto ns2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
   std::cout << "Total time: " << ns2.count() << "ns" << std::endl;

   return 0;
}
