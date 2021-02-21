#ifndef stack_h
#define stack_h

namespace StackBfost
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
    class Stack
    {
    public:
        Stack();
        Stack(const Stack<T> &aStack); // copy ctr
        Stack<T> &operator=(const Stack<T> &rightSide);
        virtual ~Stack();
        void push(const T &stackFrame);
        T pop();
        bool isEmpty() const;

    private:
        Node<T> *top;
    }
}

#endif