#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "queueArray.h"

int main() {

   QueueArray<int> q = { 0, 1, 2, 3, 4 };
   QueueArray<char> q2 = QueueArray<char>(3);
   QueueArray<string> q3 = QueueArray<string>(2);

   for (int i = 0; i < 5; i++) {
      cout << q.dequeue() << endl;
   }
   q.enqueue(11);
   q.enqueue(22);
   q.enqueue(33);
   q.enqueue(44);
   q.enqueue(55);
   cout << (q.enqueue(66) ? "enqueued 66" : "did not enqueue 66") << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;

   q2.enqueue('a');
   cout << q2.dequeue() << endl;
   cout << q2.dequeue() << endl;
   q2.enqueue('b');
   cout << q2.dequeue() << endl;
   cout << q2.dequeue() << endl;
   q2.enqueue('c');
   cout << q2.dequeue() << endl;
   cout << q2.dequeue() << endl;
   q2.enqueue('d');
   cout << q2.dequeue() << endl;

   q3.enqueue("one");
   cout << q3.dequeue() << endl;
   cout << q3.dequeue() << endl;
   q3.enqueue("two");
   q3.enqueue("three");
   q3.enqueue("four");
   cout << q3.dequeue() << endl;
   cout << q3.dequeue() << endl;

   return 0;
}
