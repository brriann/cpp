
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

const int N = 10;

void bubbleSort(vector<int>& v)
{
   bool doSwap = true;
   while (doSwap)
   {
      doSwap = false;
      for (size_t i = 0; i < v.size() - 1; i++)
      {
         // bubble smallest values to end
         if (v[i] < v[i + 1])
         {
            v[i] += v[i + 1];
            v[i + 1] = v[i] - v[i + 1];
            v[i] -= v[i + 1];
            doSwap = true;
         }
      }
   }
}

void insertInOrder(vector<int>& v, int n)
{
   int index = 0;
   while (n < v[index] && index < v.size())
   {
      index++;
   }

   for (size_t i = v.size() - 1; i > index; --i)
   {
      v[i] = v[i - 1];
   }
   v[index] = n;
   
   // TODO, research this easier vector syntax
   //auto it = std::upper_bound(v.cbegin(), v.cend(), n);
   //v.insert(it, n);
}

void printVector(vector<int> v)
{
   for (size_t i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
}

int main()
{
   // initial input of N numbers to sort
   vector<int> vec;
   for (size_t i = 0; i < N; i++)
   {
      vec.push_back(rand() % 100);
   }

   vector<int> vec2(vec);

   // user input for kth largest value to find
   string input;
   int k;
   cout << "Enter k: ";
   cin >> k;

   // safecheck
   if (k > N - 1)
   {
      return 1;
   }

   // #1 attempt : naive : bubblesort (descending) N numbers, report k-1'th index
   bubbleSort(vec);

   cout << "The " << k << "'th largest value is: " << vec[k - 1];

   cout << "\nThe vector:\n\n";
   printVector(vec);

   // #2 attempt: naive-- : insert first k of N numbers into vector, bubblesort
   // then, read through rest of N numbers, and if a number is biggest then vec[k-1],
   // insert it at the appropriate place
   // finally report k-1'th index

   vector<int> largest;
   for (size_t i = 0; i < k; i++)
   {
      largest.push_back(vec2[i]);
   }

   bubbleSort(largest);

   for (size_t i = k; i < vec2.size(); i++)
   {
      if (vec2[i] > largest[k - 1])
      {
         insertInOrder(largest, vec2[i]);
      }
   }

   cout << "\n\nThe " << k << "'th largest value is: " << largest[k - 1];

   cout << "\nThe (unsorted) vector:\n\n";
   printVector(vec2);
   cout << "\n\nThe largest vector:\n\n";
   printVector(largest);
   cout << endl << endl;

   return 0;
}