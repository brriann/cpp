#include <iostream>
#include <set>
#include <string>
#include <cctype>

using namespace std;

// requires #include <cctype> for std::isupper
void removeCapitals(std::set<std::string>* stringSet) {
   auto it = stringSet->begin();
   while (it != stringSet->end()) {
      bool hasUpper = false;
      for (auto c : *it) {
         if (std::isupper(c)) {
            hasUpper = true;
            break;
         }
      }
      if (hasUpper) {
         it = stringSet->erase(it);
      }
      else { // no erase happened, need to increment iterator
         ++it;
      }
   }
}


int main() {
   set<string> stringSet = { "this", "THESE", "word", "wordS", "group", "gO", "stays" };

   for (auto s : stringSet) {
      cout << s << endl;
   }
   cout << endl << "-------------------" << endl;
   removeCapitals(&stringSet);

   for (auto s : stringSet) {
      cout << s << endl;
   }

   return 0;
}