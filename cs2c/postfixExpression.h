#pragma once
#ifndef postfix_expression_h
#define postfix_expression_h

#include <string>
#include <set>
#include <stack>

using std::string;
using std::set;
using std::stack;

namespace postfixExpression {
   // valid operators
   set<char> operators{ '*', '+' };

   int evaluatePostfixExpression(string postfixExpression) {
      stack<int> parsedSymbols;
      // default value
      int result = -88;

      for (char c : postfixExpression)
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

      return result;
   }
}

#endif