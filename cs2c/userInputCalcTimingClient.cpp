
// This is a simple client for reference
// Demonstrating getline + istringstream for user input
// and chrono for timing

#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

using std::string;

using std::cin;
using std::getline;
using std::istringstream;

using std::cout;
using std::endl;

using std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration;

string userInputString;
unsigned long long int userInputInt;

int main()
{
   int attempts = 0;

   while (attempts++ < 10)
   {
      do
      {
         cout << "\nEnter n to calculate sum of 1 to n: ";

         getline(cin, userInputString);
         istringstream(userInputString) >> userInputInt;
      } while (userInputInt < 1);

      cout << "\n\nCalculating sum of 1 + 2 + ... + n, for n = " << userInputInt;

      unsigned long long int sumResult = 0;

      // record start time
      time_point<steady_clock> start = steady_clock::now();

      // run calculation
      for (int i = userInputInt; i > 0; i--)
      {
         sumResult += i;
      }

      // record stop time and calculate duration
      time_point<steady_clock> stop = steady_clock::now();
      duration<double> elapsedSeconds = stop - start;
      double elapsedSecondsDouble = elapsedSeconds.count();

      cout << "\nSum from 1 to " << userInputInt << " is: " << sumResult;

      cout << "\n\nCalculation took: " << elapsedSecondsDouble;
   }
   return 0;
}