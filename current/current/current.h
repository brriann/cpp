#pragma once
#ifndef postfix_expression_h
#define postfix_expression_h

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <stack>

using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::set;
using std::stack;
using std::string;
using std::stringstream;

namespace postfixExpression
{

   class SimpleBinaryTree
   {
      struct Node
      {
         char oper;
         Node* left, * right;
         Node(const char& oper) : oper(oper), left(nullptr), right(nullptr) {}

         void print(int depth = 0) const
         {
            if (left != nullptr)
            {
               left->print(depth + 1);
            }
            for (int i = 0; i < depth; ++i)
            {
               cout << "  ";
            }
            cout << oper << endl;
            if (right != nullptr)
            {
               right->print(depth + 1);
            }
         }

         void insertLeft(Node* &leftNode)
         {
            left = leftNode;
         }

         void insertRight(Node* &rightNode)
         {
            right = rightNode;
         }
      };

   public:
      Node* root;
      SimpleBinaryTree() : root(nullptr) {}
      SimpleBinaryTree(char charCtr)
      {
         root = new Node(charCtr);
      }
      ~SimpleBinaryTree()
      {
         // TODO lets just leak memory for now
      }
      void print() {
         if (root != nullptr) {
            root->print();
         }
      }
      void insertLeft(Node* &leftNode) {
         if (root == nullptr) {
            return;
         }
         else {
            root->insertLeft(leftNode);
         }
      }
      void insertRight(Node* &rightNode) {
         if (root == nullptr) {
            return;
         }
         else {
            root->insertRight(rightNode);
         }
      }
   };

   // valid operators
   set<char> operators{ '*', '+' };

   // abc*+de*f+g*+
   int evaluatePostfixExpression(string postfixExpression)
   {
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

   // a+b*c+(d*e+f)*g
   // abc*+de*f+g*+
   string convertInfixToPostfix(string postfixExpression)
   {

      const char LEFT_PAREN = '(';
      const char RIGHT_PAREN = ')';

      // valid operators
      set<char> operators{ '*', '+', '(', ')' };

      map<char, int> inputPrecedence;
      inputPrecedence['+'] = 2;
      inputPrecedence['*'] = 4;
      inputPrecedence['('] = 5;

      map<char, int> stackPrecedence;
      inputPrecedence['('] = 1;
      inputPrecedence['+'] = 2;
      inputPrecedence['*'] = 4;

      stack<char> parsedOperators;

      stringstream output;

      for (char c : postfixExpression)
      {
         // if symbol is a number (aka, "not an operator")
         if (operators.find(c) == operators.end())
         {
            output << c;
         }
         else
         { // c is operator
            switch (c)
            {
               case RIGHT_PAREN:
                  while (!parsedOperators.empty() && parsedOperators.top() != LEFT_PAREN)
                  {
                     // output operators until left paren is reached
                     output << parsedOperators.top();
                     parsedOperators.pop();
                  }
                  // pop left paren, but don't output
                  if (!parsedOperators.empty())
                  {
                     parsedOperators.pop();
                  }
                  break;
               default:
                  if (parsedOperators.empty())
                  {
                     parsedOperators.push(c);
                  }
                  else
                  {
                     while (!parsedOperators.empty() && inputPrecedence[c] <= stackPrecedence[parsedOperators.top()])
                     {
                        output << parsedOperators.top();
                        parsedOperators.pop();
                        if (parsedOperators.empty())
                        {
                           break;
                        }
                     }
                     parsedOperators.push(c);
                  }

                  break;
            }
         }
      }

      return output.str();
   }
}

#endif