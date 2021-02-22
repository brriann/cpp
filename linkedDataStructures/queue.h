
#ifndef queue_h
#define queue_h

namespace QueueBfost
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
    class Queue
    {
    public:
        Queue();
        Queue(const Queue<T>& qQueue); //copy ctr
        Queue<T>& operator =(const Queue<T>& rightSide);
        virtual ~Queue();
        void add(T item);
        T remove();
        bool isEmpty() const;
    private:
        Node<T> *front;
        Node<T> *back;
    };
}

#endif //queue_h