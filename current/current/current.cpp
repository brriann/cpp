#include <iostream>  // std::cout, std::endl
#include <map>

using namespace std;


unsigned long long avlHeightMemo(int n, map<int, unsigned long long>& cache) {
   if (n <= 1) { // h(0) = 0, h(1) = 1
      return n;
   }

   auto cached_it = cache.find(n);
   if (cached_it != cache.end()) {
      return cached_it->second;
   }

   int result = 1 + avlHeightMemo(n - 1, cache) + avlHeightMemo(n - 2, cache);
   cache[n] = result;
   return result;
}

int main() {
   map<int, unsigned long long> avlHeightCache;

   for (int i = 0; i < 100; i++) {
      cout << i << " : " << avlHeightMemo(i, avlHeightCache) << endl;
   }

   return 0;
}