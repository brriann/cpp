#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length);

int main()
{
  int a[] = {3, 10, 9, 2, 5, 1};
  
  bubbleSort(a, 6);
  for (int i = 0; i < 6; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}

void bubbleSort(int arr[], int length)
{
  for (int i = length - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[j + 1)
      {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
