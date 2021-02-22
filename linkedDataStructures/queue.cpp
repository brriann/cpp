#include <cstdlib>
#include "queue.h"

namespace QueueBfost
{
    template <class T>
    Queue<T>::Queue() : front(nullptr), back(nullptr)
    {
        // intentionally empty
    }

    template <class T>
    Queue<T>::Queue(const Queue<T> &qQueue) //copy ctr
    {
        if (aQueue.isEmpty())
        {
            front = back = nullptr;
        }
        else
        {
            Node<T> *temp = aQueue.front; //temp moves
            //through the nodes from front to back of aQueue.
            back = new Node<T>(temp->getData(), nullptr);
            front = back;
            //First node created and filled with data.
            //New nodes are now added AFTER this first node.
            temp = temp->getLink(); //temp now points to second
            //node or nullptr if there is no second node.
            while (temp != nullptr)
            {
                back->setLink(new Node<T>(temp->getData(), nullptr));
                back = back->getLink();
                temp = temp->getLink();
            }
            //back->link == nullptr
        }
    }

    template <class T>
    Queue<T> &Queue<T>::operator=(const Queue<T> &rightSide)
    {
        if (front == rightSide.front) //if the queues are the same
        {
            return *this;
        }
        else //send left side back to freestore
        {
            T next;
            while (!isEmpty())
                next = remove(); //remove calls delete.
        }
        if (rightSide.isEmpty())
        {
            front = back = nullptr;
            return *this;
        }
        else
        {
            Node<T> *temp = rightSide.front; //temp moves
            //through the nodes from front to back of rightSide.
            back = new Node<T>(temp->getData(), nullptr);
            front = back;
            //First node created and filled with data.
            //New nodes are now added AFTER this first node.
            temp = temp->getLink(); //temp now points to second
            //node or nullptr if there is no second node.
            while (temp != nullptr)
            {
                back->setLink(
                    new Node<T>(temp->getData(), nullptr));
                back = back->getLink();
                temp = temp->getLink();
            }
            //back->link == nullptr;
            return *this;
        }
    }

    template <class T>
    Queue<T>::~Queue()
    {
        T next;
        while (!isEmpty())
        {
            next = remove(); // remove calls delete
        }
    }

    template <class T>
    void Queue<T>::add(T item)
    {
        if (isEmpty())
        {
            front = back = new Node<T>(item, nullptr);
        }
        else
        {
            back->setLink(new Node<T>(item, nullptr));
            back = back->getLink();
        }
    }

    template <class T>
    T Queue<T>::remove()
    {
        if (isEmpty())
        {
            exit(1); // error, remove item from empty queue
        }

        T result = front->getData();
        Node<T> *discard;
        discard = front;
        front = front->getLink();

        if (front == nullptr) // if removed the last node
        {
            back = nullptr;
        }

        delete discard;
        return result;
    }

    template <class T>
    bool Queue<T>::isEmpty() const
    {
        return (back == nullptr); // or front == nullptr
    }
}