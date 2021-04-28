#pragma once
#ifndef queue_array_h
#define queue_array_h

#include <memory>

template<typename T>
class QueueArray {
   int front;
   int back;
   int currentSize;
   int capacity;
   T* queue;
   void incrementWithWrap(int& index) {
      if (index == capacity - 1) {
         index = 0;
      }
      else {
         ++index;
      }
   }
   QueueArray() {
      front = back = capacity = currentSize = 0;
      queue = nullptr;
   }
public:
   QueueArray(int capacityCtr) : QueueArray() {
      queue = new T[capacityCtr];
      capacity = capacityCtr;
   }
   QueueArray(std::initializer_list<T> list) : QueueArray() {
      queue = new T[list.size()];
      capacity = list.size();
      for (auto elt : list) {
         enqueue(elt);
      }
   }
   ~QueueArray() {
      delete[] queue;
   }
   bool enqueue(T newElement) {
      if (currentSize == capacity) {
         return false;
      }

      queue[back] = newElement;
      incrementWithWrap(back);

      ++currentSize;
      return true;
   }
   T dequeue() {
      if (currentSize < 1) {
         return T();
      }

      T valueToReturn = queue[front];

      incrementWithWrap(front);

      --currentSize;
      return valueToReturn;
   }
   int size() {
      return currentSize;
   }
};

#endif