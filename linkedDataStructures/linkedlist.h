#ifndef linkedlist_h
#define linkedlist_h

namespace LinkedListBfost
{
    template <class T>
    class Node
    {
    public:
        Node(const T &theData, Node<T> *theLink) : data(theData), link(theLink) {}
        Node<T>* getLink() const { return link; }
        const T getData() const { return data; }
        void setData(const T& theData) { data = theData; }
        void setLink(Node<T>* pointer) { link = pointer; }
    private:
        T data;
        Node<T> *link;
    };

    template<class T>
    void headInsert(Node<T>*& theHead, const T& theData);

    template<class T>
    void insert(Node<T>* afterMe, const T& theData);

    template<class T>
    void deleteNode(Node<T>* before);

    template<class T>
    void deleteFirstNode(Node<T>*& theHead);

    template<class T>
    Node<T>* search(Node<T>* theHead, const T& target);
}

#endif // linkedlist_h