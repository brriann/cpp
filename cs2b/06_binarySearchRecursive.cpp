// Binary search - recursive

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
   int mid;
   if (first > last)
   {
      found = false;
   }
   else
   {
      mid = (first + last) / 2;

      if (key == a[mid])
      {
         found = true;
         location = mid;
      }
      else if (key < a[mid])
      {
         // last = mid - 1
         search(a, first, mid - 1, key, found, location);
      }
      else if (key > a[mid])
      {
         // first = mid + 1
         search(a, mid + 1, last, key, found, location);
      }
   }
}