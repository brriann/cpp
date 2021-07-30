#include <iostream>  // std::cout, std::endl
#include <chrono>
#include <map>

using namespace std;


class SimpleTimer {
  std::chrono::time_point<std::chrono::steady_clock> start_time;

public:
  void start() {
    start_time = std::chrono::steady_clock::now();
  }

  // Return the number of seconds since .start() was called
  double elapsed_seconds() const {
    std::chrono::duration<double> diff(std::chrono::steady_clock::now() - start_time);
    return diff.count();
  }
};

unsigned long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

unsigned long long fibMemo(int n, map<int, unsigned long long>& cache) {
    if (n <= 1) {
        return n;
    }

    auto cached_it = cache.find(n);
    if (cached_it != cache.end()) {
        return cached_it->second;
    }

    int result = fibMemo(n - 1, cache) + fibMemo (n - 2, cache);
    cache[n] = result;
    return result;
}

int main() {
    map<int, unsigned long long> fibCache;
    for (int i = 0; i < 100; i++) {
        SimpleTimer timer;
        timer.start();
        cout << i << " " << fibMemo(i, fibCache) << " " << timer.elapsed_seconds() << endl;
    }
    for (int i = 0; i < 50; i++) {
        SimpleTimer timer;
        timer.start();
        cout << i << " " << fib(i) << " " << timer.elapsed_seconds() << endl;
    }
    return 0;
}