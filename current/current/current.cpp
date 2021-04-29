
#include <iostream>
#include <string>

#include "current.h"

using std::string;
using postfixExpression::convertInfixToPostfix;
using postfixExpression::evaluatePostfixExpression;

// a + b * c + ( d * e + f ) * g
// a b c * + d e * f + g * +

// 6* (5 + ((2 + 3) * 8)) + 3)

const string POSTFIX_EXPRESSION = "6523+8*+3+*";
const string INFIX_EXPRESSION = "6*(5+((2+3)*8))+3)";

map<string, string> expressionMap = {
   {"((((3+5)*1)*(2*(8+9)))*2)", "35+1*289+**2*"},
   {"6*(5+((2+3)*8))+3)", "6523+8*+3+*"},
   {"(((1+2)))", "12+"},
};

int main()
{
   for (auto str : {
      "6523+8*+3+*",
      "65+238*3++*",
      "12+"
      }) {
      std::cout << str << " : " << evaluatePostfixExpression(str) << std::endl;
   }

   for (const auto &expressionPair : expressionMap) {
      std::cout << expressionPair.first << " : " << expressionPair.second << " : " << convertInfixToPostfix(expressionPair.first) << " : " << evaluatePostfixExpression(convertInfixToPostfix(expressionPair.first)) << std::endl;
   }

   //std::cout << INFIX_EXPRESSION << " : " << convertInfixToPostfix(INFIX_EXPRESSION) << std::endl;

   return 0;
}