#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using std::ceil;
using std::cout;
using std::endl;
using std::list;
using std::log;
using std::pow;
using std::vector;

void radix_sort_10(vector<int>* nums) {
   list<int> buckets[10];

   //static_assert(sizeof(int) == 4);

   const int max_rounds = 10;
   for (int round = 0, divisor = 1; round < max_rounds; ++round, divisor *= 10) {
      for (int x : *nums) {
         int digit = x / divisor % 10;
         buckets[digit].push_back(x);
      }
      nums->clear();
      for (int i = 0; i < 10; ++i) {
         for (int x : buckets[i]) {
            nums->push_back(x);
         }
         buckets[i].clear();
      }
   }
}


// // O(log(max(nums)) / log(B) * (N + B))
// // O(log(max(nums)) / log(base) * (nums.size() + base))
// void radix_sort(vector<int>* nums, const int base=10) {
//   // O(B)
//   list<int> buckets[base];
//   static_assert(sizeof(int) == 4); // 4 bytes 32 bit int

//   // O(1)
//   const int max_rounds = ceil(log(pow(256, sizeof(int)) - 1) / log(base));
//   // O(R * (N + B))
//   for (int round = 0, divisor = 1; round < max_rounds; ++round, divisor *= base) {
//     // Place numbers in buckets according to current digit
//     // O(N)
//     for (int x : *nums) {
//       int digit = x / divisor % base;
//       buckets[digit].push_back(x);
//     }
//     // Copy numbers from buckets back to nums and clear the buckets
//     // O(N) or O(1)
//     nums->clear();
//     // O(max(N, B)) = O(N + B)
//     for (int i = 0; i < base; ++i) {
//       for (int x : buckets[i]) {
//         nums->push_back(x);
//       }
//       buckets[i].clear();
//     }
//   }
// }

int main() {
   vector<int> nums = { 12345, 164, 443, 123, 999, 0, 893, 10000 };
   radix_sort_10(&nums);
   // radix_sort(&nums, 100);
   for (int x : nums) {
      cout << x << endl;
   }
   return 0;
}


// ============================================================================
// COPIED FROM CURRENT.SLN ....
// ============================================================================
//
//#include <cmath>
//#include <iostream>
//#include <list>
//#include <vector>
//
//using std::ceil;
//using std::cout;
//using std::endl;
//using std::list;
//using std::log;
//using std::pow;
//using std::vector;
//
//void radix_sort_10(vector<int>* nums) {
//   list<int> buckets[10];
//
//   const int max_rounds = 10;
//   for (int round = 0, divisor = 1; round < max_rounds; ++round, divisor *= 10) {
//      for (int x : *nums) {
//         int digit = x / divisor % 10;
//         buckets[digit].push_back(x);
//      }
//      nums->clear();
//      for (int i = 0; i < 10; ++i) {
//         for (int x : buckets[i]) {
//            nums->push_back(x);
//         }
//         buckets[i].clear();
//      }
//   }
//}
//
//
//// O(log(max(nums)) / log(B) * (N + B))
//// O(log(max(nums)) / log(base) * (nums.size() + base))
//void radix_sort(vector<int>* nums, const int base = 10) {
//   // O(B)
//   list<int> buckets[base];
//   static_assert(sizeof(int) == 4); // 4 bytes 32 bit int
//
//   // O(1)
//   const int max_rounds = ceil(log(pow(256, sizeof(int)) - 1) / log(base));
//   // O(R * (N + B))
//   for (int round = 0, divisor = 1; round < max_rounds; ++round, divisor *= base) {
//      // Place numbers in buckets according to current digit
//      // O(N)
//      for (int x : *nums) {
//         int digit = x / divisor % base;
//         buckets[digit].push_back(x);
//      }
//      // Copy numbers from buckets back to nums and clear the buckets
//      // O(N) or O(1)
//      nums->clear();
//      // O(max(N, B)) = O(N + B)
//      for (int i = 0; i < base; ++i) {
//         for (int x : buckets[i]) {
//            nums->push_back(x);
//         }
//         buckets[i].clear();
//      }
//   }
//}
//
//int main() {
//   vector<int> nums = { 12345, 164, 443, 123, 999, 0, 893, 10000 };
//   radix_sort_10(&nums);
//   radix_sort(&nums, 100);
//   for (int x : nums) {
//      cout << x << endl;
//   }
//   return 0;
//}
