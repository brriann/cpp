// Binary search - iterative

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int ARRAY_SIZE = 10;

void search(const int a[], int first, int last, int key, bool& found, int& location);

int main()
{
   int a[ARRAY_SIZE] = { 1, 1, 3, 5, 6, 7, 8, 9, 11, 12 };
   const int finalIndex = ARRAY_SIZE - 1;

   int key, location;
   bool found;

   cout << "Enter number to be located: ";
   cin >> key;

   search(a, 0, finalIndex, key, found, location);

   if (found)
   {
      cout << key << " is in index location " << location << endl;
   }
   else
   {
      cout << key << " is not in the array." << endl;
   }

   return 0;
}

void search(const int a[], int first, int last, int key, bool& found, int& location)
{
   int firstCopy = first;
   int lastCopy = last;
   int mid;

   found = false; //initialize

   while ((first <= last) && !(found))
   {
      mid = ((first + last) / 2);

      if (key == a[mid])
      {
         found = true;
         location = mid;
      }
      else if (key < a[mid])
      {
         last = mid - 1;
      }
      else if (key > a[mid])
      {
         first = mid + 1;
      }
   }
}