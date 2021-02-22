
#include <cstdlib>
#include "stack.h"
namespace StackBfost
{
    template <class T>
    Stack<T>::Stack() : top(nullptr) {}

    template <class T>
    Stack<T>::Stack(const Stack<T> &aStack)
    {
        if (aStack.isEmpty())
        {
            top = nullptr;
        }
        else
        {
            Node<T> *temp = aStack.top;
            Node<T> *end;
            end = new Node<T>(temp->getData(), nullptr);
            top = end;
            temp = temp->getLink();

            while (temp != nullptr)
            {
                end->setLink(new Node<T>(temp->getData(), nullptr));
                temp = temp->getLink();
                end = end->getLink();
            }
            end->link = nullptr;
        }
    }

    template <class T>
    Stack<T> &Stack<T>::operator=(const Stack<T> &rightSide)
    {
        if (top == rightSide.top) //if two stacks are the same
            return *this;
        else //send left side back to freestore
        {
            T next;
            while (!isEmpty())
                next = pop(); //remove calls delete.
        }
        if (rightSide.isEmpty())
        {
            top = nullptr;
            return *this;
        }
        else
        {
            Node<T> *temp = rightSide.top; //temp moves through
            //the nodes from front top to bottom of rightSide.
            Node<T> *end; //Points to end of the left-side stack.
            end = new Node<T>(temp->getData(), nullptr);
            top = end;
            ;
            //First node created and filled with data.
            //New nodes are now added AFTER this first node.
            temp = temp->getLink(); //Move temp to second node
            //or set to nullptr if there is no second node.
            while (temp != nullptr)
            {
                end->setLink(
                    new Node<T>(temp->getData(), nullptr));
                temp = temp->getLink();
                end = end->getLink();
            }
            //end->link == nullptr;
            return *this;
        }
    }

    template <class T>
    Stack<T>::~Stack()
    {
        T next;
        while (!isEmpty())
        {
            next = pop(); // pop calls delete
        }
    }

    template <class T>
    bool Stack<T>::isEmpty() const
    {
        return (top == nullptr);
    }

    template <class T>
    void Stack<T>::push(const T &stackFrame)
    {
        // this is the same as a linked list headInsert call
        top = new Node<T>(stackFrame, top);
    }

    template <class T>
    T Stack<T>::pop()
    {
        if (isEmpty())
        {
            // error popping empty stack
            exit(1);
        }

        T result = top->getData();
        Node<T> *discard;

        discard = top;
        top = top->getLink();

        delete discard;
        return result;
    }
}