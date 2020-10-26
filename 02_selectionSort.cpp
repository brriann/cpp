#include <iostream>
using namespace std;

void fillArray(int a[], int size, int& numberUsed);

void sort(int a[], int numberUsed);

void swapValues(int& v1, int& v2);

int indexOfSmallest(const int a[], int startIndex, int numberUsed);

int main()
{
  
}

void fillArray(int a[], int size, int& numberUsed)
{
  cout << "enter up to " << size << " integers >= 0.\n"
    << "mark the end of list input with a negative number.\n"
  int next, index = 0;
  cin >> next;
  while (next >= 0 && index < size)
  {
    a[index] = next;
    index++;
    cin >> next;
  }
  numberUsed = index;
}

void sort(int a[], int numberUsed);
{

}

void swapValues(int& v1, int& v2)
{
  int temp;
  temp = v1;
  v1 = v2;
  v2 = temp;
}

int indexOfSmallest(const int a[], int startIndex, int numberUsed)
{
  int min = a[startIndex],
    indexOfMin = startIndex;
    
  for (int index = startIndex + 1; index < numberUsed; index++)
  {
    if (a[index] < min)
    {
      min = a[index];
      indexOfMin = index;
      // min is smallest of a[startIndex] through a[index]
    }
  }
  return indexOfMin;
}
