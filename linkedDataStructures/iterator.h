#ifndef iterator_h
#define iterator_h

namespace IteratorBfost
{
    template <class T>
    class Node
    {
    public:
        Node(const T &theData, Node<T> *theLink) : data(theData), link(theLink) {}
        Node<T> *getLink() const { return link; }
        const T getData() const { return data; }
        void setData(const T &theData) { data = theData; }
        void setLink(Node<T> *pointer) { link = pointer; }

    private:
        T data;
        Node<T> *link;
    };

    template <class T>
    class ListIterator
    {
    public:
        ListIterator() : current(NULL) {}
        ListIterator(Node<T> *initial) : current(initial) {}
        const T& operator *() const { return current->getData(); }
        ListIterator& operator++() //prefix form
        {
            current = current->getLink();
            return *this;
        }
        ListIterator operator ++(int) //suffix form
        {
            ListIterator startVersion(current);
            current = current->getLink();
            return startVersion;
        }
        bool operator ==(const ListIterator& rightSide) const
        {
            return (current == rightSide.current);
        }
        bool operator !=(const ListIterator& rightSide) const
        {
            return (current != rightSide.current);
        }
        // default assignment operator and copy str should work correctly.
    private:
        Node<T> *current;
    };
}

#endif //iterator_h