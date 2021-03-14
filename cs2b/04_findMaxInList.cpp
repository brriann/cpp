#include <iostream>
using namespace std;

int main()
{
  int i, score[5], max;
  
  cout << "enter five scores.\n";
  cin >> score[0];
  max = score[0];
  for (int i = 1; i < 5; i++)
  {
    cin >> score[i];
    if (score[i] > max)
      max = score[i];
  }
  cout << "highest score is " << max << endl;
}
