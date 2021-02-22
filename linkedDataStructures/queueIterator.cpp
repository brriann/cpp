#include <cstdlib>
#include "queueIterator.h" //QueueIterator, "Queue with Iterator"

using namespace IteratorBfost; //ListIterator

namespace QueueIteratorBfost
{
    template <class T>
    QueueIterator<T>::QueueIterator() : front(nullptr), back(nullptr)
    {
        // intentionally empty
    }

    template <class T>
    QueueIterator<T>::QueueIterator(const QueueIterator<T> &qQueue)
    {
        if (aQueue.isEmpty())
            front = back = nullptr;
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
    QueueIterator<T> &QueueIterator<T>::operator=(const QueueIterator<T> &rightSide)
    {
        if (front == rightSide.front) //if the queues are the same
            return *this;
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
    QueueIterator<T>::~QueueIterator()
    {
        T next;
        while (!isEmpty())
        {
            next = remove(); //remove calls delete.
        }
    }

    template <class T>
    void QueueIterator<T>::add(T item)
    {
        if (isEmpty())
            front = back = new Node<T>(item, nullptr); //Sets both
        //front and back to point to the only node
        else
        {
            back->setLink(new Node<T>(item, nullptr));
            back = back->getLink();
        }
    }

    template <class T>
    T QueueIterator<T>::remove()
    {
        if (isEmpty())
        {
            exit(1); // error removing item from empty queue
        }

        T result = front->getData();
        Node<T> *discard;
        discard = front;
        front = front->getLink();

        if (front == nullptr) //if you removed the last node
        {
            back = nullptr;
        }

        delete discard;
        return result;
    }

    template <class T>
    bool QueueIterator<T>::isEmpty() const
    {
        return (back == nullptr); //front == nullptr would also work
    }
}