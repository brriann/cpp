#include "linkedlist.h"

namespace LinkedListBfost
{
    template <class T>
    void headInsert(Node<T> *&theHead, const T &theData)
    {
        head = new Node<T>(theData, theHead);
    }

    template <class T>
    void insert(Node<T> *afterMe, const T &theData)
    {
        afterMe->setLink(new Node<T>(theData, afterMe->getLink()));
    }

    template <class T>
    void deleteNode(Node<T> *before)
    {
        Node<T> *discard;
        discard = before->getLink();
        before->setLink(discard->getLink());
        delete discard;
    }

    template <class T>
    void deleteFirstNode(Node<T> *&theHead)
    {
        Node<T> *discard;
        discard = theHead;
        theHead = theHead->getLink();
        delete discard;
    }

    template <class T>
    Node<T> *search(Node<T> *theHead, const T &target)
    {
        Node<T> *here = theHead;
        if (here == nullptr) // empty list
        {
            return nullptr;
        }
        else
        {
            while (here->getData() != target && here->getLink() != nullptr)
            {
                here = here->getLink();
            }
            if (here->getData() == target)
            {
                return here;
            }
            else
            {
                return nullptr;
            }
        }
    }
}