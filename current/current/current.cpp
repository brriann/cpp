
#include <iostream>
#include <string>

#include "current.h"

using std::string;
using expressions::SimpleBinaryTree;
using expressions::convertInfixToPostfix;
using expressions::evaluatePostfixExpression;
using expressions::convertPostfixToExpressionTree;

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
   for (string s : {"ab+cde+**", "6523+8*+3+*", "35+1*289+**2*"}) {
      SimpleBinaryTree* expressionTree = convertPostfixToExpressionTree(s);
      expressionTree->print();
      cout << endl << endl;
      expressionTree->toInfix();
      cout << endl << endl;
      expressionTree->toPostfix();
      cout << endl << endl;
   }

   SimpleBinaryTree tree = SimpleBinaryTree('*');
   SimpleBinaryTree tree2 = SimpleBinaryTree('4');
   SimpleBinaryTree tree3 = SimpleBinaryTree('5');
   SimpleBinaryTree tree4 = SimpleBinaryTree('+');
   tree.insertLeft(tree2.root);
   tree.insertRight(tree3.root);

   SimpleBinaryTree tree5 = SimpleBinaryTree('1');
   tree4.insertLeft(tree.root);
   tree4.insertRight(tree5.root);

   tree4.print();

   cout << endl << endl;

   tree4.toInfix();

   cout << endl << endl;

   tree4.toPostfix();

   cout << endl << endl;

   for (auto str : {
      "6523+8*+3+*",
      "65+238*3++*",
      "12+"
      }) {
      std::cout << str << " : " << evaluatePostfixExpression(str) << std::endl;
   }

   for (const auto& expressionPair : expressionMap) {
      std::cout << expressionPair.first << " : " << expressionPair.second << " : " << convertInfixToPostfix(expressionPair.first) << " : " << evaluatePostfixExpression(convertInfixToPostfix(expressionPair.first)) << std::endl;
   }

   //std::cout << INFIX_EXPRESSION << " : " << convertInfixToPostfix(INFIX_EXPRESSION) << std::endl;

   return 0;
}