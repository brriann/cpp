
#include <vector>
#include <string>

using std::vector;
using std::string;

const int NOT_FOUND = -1;

template<typename Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x)
{
   int low = 0, high = a.size() - 1;

   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (a[mid] < x)
      {
         low = mid + 1;
      }
      else if (a[mid] > x)
      {
         high = mid - 1;
      }
      else
      {
         return mid; // found
      }
   }

   return NOT_FOUND;
}

// test client
int main()
{
   vector<int> intVector = { 1, 2, 5, 6, 8, 12, 22, 23, 24, 25, 27 };

   int intTarget = 25;

   vector<string> stringVector = { "aardvark", "alligator", "crocodile", "duck", "elephant", "kangaroo", "monster", "ocelot", "pokemon", "rhino", "zebra" };

   string stringTarget = "alligator";

   int intLocation = binarySearch(intVector, intTarget);
   int stringLocation = binarySearch(stringVector, stringTarget);

   return 0;
}