#include <iostream>
using namespace std;
const int DECLARED_SIZE = 20;

void fillArray(int a[], int size, int& numberUsed);

int search(const int a[], int numberUsed, int target);

int main()
{
  int arr[DECLARED_SIZE], listSize, target;
  
  fillArray(arr, DECLARED_SIZE, listSize);
  
  char ans;
  int result;
  do
  {
    cout << "enter a number to search for: ";
    cin >> target;
    
    result = search(arr, listSize, target);
    if (result == -1)
      cout << target << " is not in the list.\n";
    else
      cout << target << " is stored in array position "
        << result << endl
        << "(remember, array is 0-indexed.\n";
    cout << "search again? y/n + Enter key :: ";
    cin >> ans;
  } while ((ans != 'n') && (ans != 'N'));
  cout << "end of program.\n";
  return 0;
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

int search(const int a[], int numberUsed, int target)
{
  int index = 0;
  bool found = false;
  while (!found && index < numberUsed)
  {
    if (target == a[index])
      found = true;
    else
      index++;
  }
  return found ? index : -1;
}
