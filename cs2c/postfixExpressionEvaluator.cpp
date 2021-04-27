
#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <string>

using std::stack;
using std::map;
using std::set;
using std::string;

// a + b * c + ( d * e + f ) * g
// a b c * + d e * f + g * +

// 6* (5 + ((2 + 3) * 8)) + 3)

const string POSTFIX_EXPRESSION = "6523+8*+3+*";

set<char> operators{ '*', '+' };

int main()
{
   stack<int> parsedSymbols;
   int result;

   for (char c : POSTFIX_EXPRESSION)
   {
      // if symbol is a number (aka, "not an operator")
      if (operators.find(c) == operators.end())
      {
         parsedSymbols.push(c - '0'); // ASCII, 0-9 = 48-57
      }
      else
      {
         int lhs = parsedSymbols.top();
         parsedSymbols.pop();

         int rhs = parsedSymbols.top();
         parsedSymbols.pop();

         switch (c)
         {
            case '*':
               result = lhs * rhs;
               break;
            case '+':
               result = lhs + rhs;
               break;
            default:
               break;
         }
         parsedSymbols.push(result);
      }
   }

   std::cout << "result: " << result << std::endl;

   return 0;
}