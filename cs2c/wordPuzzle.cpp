#include <iostream>
#include <string>
#include <map>
#include "matrixTemplate.cpp"

using std::string;
using std::map;
using std::cout;
using std::endl;

string boolToString(bool stringifyMe)
{
   string rep = stringifyMe ? "true" : "false";
   return rep;
}

string toString(char* a, int size)
{
   string s = "";
   for (int i = 0; i < size; i++)
   {
      s = s + a[i];
   }
   return s;
}

bool searchPuzzle(string word, matrix<char>& puzzle)
{
   size_t dim = puzzle.numCols();
   size_t wordLen = word.length();
   
   // iterate rows
   for (size_t i = 0; i < dim; i++)
   {
      // iterate cols
      for (size_t j = 0; j < dim; j++)
      {
         // search forward horizontal
         if (dim - j < wordLen)
         {
            continue;
         }

         char* peek = new char[wordLen];
         for (size_t k = 0; k < wordLen; k++)
         {
            peek[k] = puzzle[i][j + k];
         }
         if (word == toString(peek, wordLen))
         {
            delete[] peek;
            peek = nullptr;
            return true;
         }
         delete[] peek;
         peek = nullptr;

         // search down vertical
         if (dim - i < wordLen)
         {
            continue;
         }

         peek = new char[wordLen];
         for (size_t l = 0; l < wordLen; l++)
         {
            peek[l] = puzzle[i+l][j];
         }
         if (word == toString(peek, wordLen))
         {
            delete[] peek;
            peek = nullptr;
            return true;
         }
         delete[] peek;
         peek = nullptr;
      }
   }
}

int main()
{
   vector<vector<char> > wordPuzzleVec = 
   { 
      {'c', 'o', 'l', 'a', 'x'},
      {'x', 'r', 'i', 'x', 'x'},
      {'x', 'a', 't', 'x', 'x'},
      {'x', 'w', 'x', 'a', 'x'},
      {'t', 'a', 'c', 'x', 'r'},
   };

   vector<string> wordList = 
   {
      "cola",
      "cat",
      "rat",
      "war",
      "lit",
   };

   map<string, bool> results;

   matrix<char> wordPuzzle = matrix<char>(wordPuzzleVec);

   // search for each word
   for (string word : wordList)
   {
      results[word] = searchPuzzle(word, wordPuzzle);
   }

   // display results
   map<string, bool>::iterator it;
   for (it = results.begin(); it != results.end(); it++)
   {
      cout << it->first << " = " << boolToString(it->second) << endl;
   }

   return 0;
}