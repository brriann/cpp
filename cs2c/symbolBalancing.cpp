
#include <stack>
#include <map>
#include <string>

using std::stack;
using std::map;
using std::string;

template<typename T>
bool valueExistsInMap(map<T, T> map, T find)
{
   bool found = false;
   auto it = map.begin();
   while (it != map.end())
   {
      found = (it->second == find);
      if (found)
      {
         break;
      }
      ++it;
   }
   return found;
}

int main()
{
   map<char, char> symbolPairs{
      {'}', '{'},
      /*{']', '['},*/
      //{'>', '<'}, // need better syntax parsing for gt/lt compares...
      {')', '('},
      //{'"', '"'},
      //{'\'', '\''},
   };

   stack<char> symbolStack;

   string codeToAnalyze = "void func(int a) { if (a > 0) {//todo} else if (a < 0) {//todo} else {// todo} }";

   for (char& c : codeToAnalyze)
   {
      // opening symbols
      if (valueExistsInMap(symbolPairs, c))
      {
         symbolStack.push(c);
      }
      else
      {
         // closing symbols
         map<char, char>::iterator search = symbolPairs.find(c);
         if (search != symbolPairs.end())
         {
            if (symbolStack.empty())
            {
               // TODO throw from helper func
               return 1;
            }
            else
            {
               char topOfStack = symbolStack.top();
               symbolStack.pop();

               if (search->second != topOfStack)
               {
                  return 1;
               }
            }
         }
      }
   }
   if (!symbolStack.empty())
   {
      return 1;
   }

   return 0;
}
