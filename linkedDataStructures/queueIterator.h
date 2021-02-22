#ifndef queueiterator_h
#define queueiterator_h

#include "iterator.h"

using namespace IteratorBfost;

namespace QueueIteratorBfost
{
    template <class T>
    class QueueIterator
    {
    public:
        QueueIterator();
        QueueIterator(const QueueIterator<T>& qQueue); //copy ctr
        QueueIterator<T>& operator=(const QueueIterator<T>& rightSide);
        virtual ~QueueIterator();
        void add(T item);
        T remove();
        bool isEmpty() const;
        ListIterator begin() const { return ListIterator(front); }
        ListIterator end() const { return ListIterator(); }
        // using iterator
        // for (int i = q.begin(); i != q.end(); i++)
    private:
        Node<T> *front;
        Node<T> *back;
    };
}

#endif