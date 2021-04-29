#include <iostream>
#include <string>

#include "postfixExpression.h"

using std::string;
using postfixExpression::evaluatePostfixExpression;

// a + b * c + ( d * e + f ) * g
// a b c * + d e * f + g * +

// 6* (5 + ((2 + 3) * 8)) + 3)

const string POSTFIX_EXPRESSION = "6523+8*+3+*";

int main()
{
   std::cout << "result: " << evaluatePostfixExpression(POSTFIX_EXPRESSION) << std::endl;

   return 0;
}