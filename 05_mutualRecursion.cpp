// current.cpp : This file contains the 'main' function. Program execution begins and ends there.
// boilerplate Windows/Visual Studio project

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

bool evenNumberOfOnes(string s);
bool oddNumberOfOnes(string s);

// if the recursive calls end in this function with an empty string,
// then the string had an even number of 1's
bool evenNumberOfOnes(string s)
{
   if (s.length() == 0)
   {
      return true; // is even
   }
   else if (s[0] == '1')
   {
      return oddNumberOfOnes(s.substr(1));
   }
   else
   {
      return evenNumberOfOnes(s.substr(1));
   }
}

// if the recursive calls end in this function with an empty string,
// then the string had an odd number of 1's
bool oddNumberOfOnes(string s)
{
   if (s.length() == 0)
   {
      return false; // is even
   }
   else if (s[0] == '1')
   {
      return evenNumberOfOnes(s.substr(1));
   }
   else
   {
      return oddNumberOfOnes(s.substr(1));
   }
}

int main()
{
   string s = "110011";

   if (evenNumberOfOnes(s)) // 0 occurences is even, so start with evenNumberOfOnes()
   {
      cout << "Even number of ones." << endl;
   }
   else
   {
      cout << "Odd number of ones." << endl;
   }
   return 0;
}
