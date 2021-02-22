#include <iostream>
#include "set.h"

using LinkedListBfost::Node;
using LinkedListBfost::search;
using LinkedListBfost::headInsert;

namespace SetBfost
{
    template <class T>
    Set<T>::~Set()
    {
        Node<T> *toDelete = head;
        while (head != nullptr)
        {
            head = head->getLink();
            delete toDelete;
            toDelete = head;
        }
    }

    template <class T>
    bool Set<T>::contains(T target) const
    {
        Node<T>* result = search(head, target);
        if (result == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    template <class T>
    void Set<T>::add(T item)
    {
        if (search(head, item) == nullptr)
        {
            headInsert(head, item);
        }
    }
    
    template <class T>
    void Set<T>::output()
    {
        Node<T> *iterator = head;
        while (iterator != nullptr)
        {
            std::cout << iterator->getData() << " ";
            iterator = iterator->getLink();
        }
    }
    
    template <class T>
    Set<T>* Set<T>::setUnion(const Set<T> &otherSet)
    {
        Set<T> *unionSet = new Set<T>();
        Node<T> *iterator = head;
        while (iterator != nullptr)
        {
            unionSet->add(iterator->getData());
            iterator = iterator->getLink();
        }
        iterator = otherSet.head;
        while (iterator != nullptr)
        {
            unionSet->add(iterator->getData());
            iterator = iterator->getLink()
        }
        return unionSet;
    }
    
    template <class T>
    Set<T>* Set<T>::setIntersection(const Set<T> &otherSet)
    {
        Set<T> *interSet = new Set<T>();
        Node<T> *iterator = head;
        while (iterator != nullptr)
        {
            if (otherSet.contains(iterator->getData()))
            {
                interSet->add(iterator->getData());
            }
            iterator = iterator->getLink();
        }
        return interSet;
    }
}