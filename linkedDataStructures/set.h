#ifndef set_h
#define set_h

#include "linkedlist.h"

using LinkedListBfost::Node;

namespace SetBfost
{
    template <class T>
    class Set
    {
    public:
        Set() { head = nullptr; }
        // copy ctr... TODO
        // overloaded = operator ... TODO
        virtual ~Set();
        bool contains(T target) const;
        void add(T item);
        void output();
        Set<T> *setUnion(const Set<T> &otherSet);
        Set<T> *setIntersection(const Set<T> &otherSet);
    private:
        Node<T> *head;
    };
}

#endif //set_h