#include <iostream>

using namespace std;

class QueueArray {
   int front;
   int back;
   int currentSize;
   int capacity;
   int* queue;
   void incrementWithWrap(int&);
public:
   QueueArray();
   QueueArray(int);
   QueueArray(initializer_list<int> list);
   ~QueueArray();
   bool enqueue(int);
   int dequeue();
   int size();
};

QueueArray::QueueArray() {
   front = back = capacity = currentSize = 0;
   queue = nullptr;
}

QueueArray::QueueArray(int capacityCtr) : QueueArray() {
   queue = new int[capacityCtr];
   capacity = capacityCtr;
}

QueueArray::QueueArray(initializer_list<int> list) : QueueArray() {
   queue = new int[list.size()];
   capacity = list.size();
   for (auto elt : list) {
      enqueue(elt);
   }
}

QueueArray::~QueueArray() {
   delete[] queue;
}

bool QueueArray::enqueue(int newElement) {
   if (currentSize == capacity) {
      return false;
   }

   queue[back] = newElement;
   incrementWithWrap(back);

   ++currentSize;
   return true;
}

int QueueArray::dequeue() {
   if (currentSize < 1) {
      return 8855;
   }

   int valueToReturn = queue[front];

   incrementWithWrap(front);

   --currentSize;
   return valueToReturn;
}

int QueueArray::size() {
   return currentSize;
}

void QueueArray::incrementWithWrap(int& index) {
   if (index == capacity - 1) {
      index = 0;
   }
   else {
      ++index;
   }
}

int main() {

   QueueArray q = { 0, 1, 2, 3, 4 };
   QueueArray q2 = QueueArray();
   QueueArray q3 = QueueArray(5);

   for (int i = 0; i < 5; i++) {
      cout << q.dequeue() << endl;
   }
   q.enqueue(12);
   q.enqueue(22);
   q.dequeue();
   q.enqueue(13);
   q.enqueue(33);
   q.dequeue();
   q.enqueue(14);
   q.enqueue(44);
   q.dequeue();
   q.enqueue(15);
   q.enqueue(55);
   q.dequeue();
   q.enqueue(16);
   q.enqueue(66);
   q.dequeue();
   
   q.enqueue(66);

   for (int i = 0; i < 5; i++) {
      cout << q.dequeue() << endl;
   }

   return 0;
}