
class DoublyLinkedIntNode
{
public:
    DoublyLinkedIntNode() {}
    DoublyLinkedIntNode(int theData, DoublyLinkedIntNode *previous, DoublyLinkedIntNode *next)
        : data(theData), nextLink(next), previousLink(previous) {}
    DoublyLinkedIntNode *getNextLink() const { return nextLink; }
    DoublyLinkedIntNode *getPreviousLink() const { return previousLink; }
    int getData() const { return data; }
    void setData(int theData) { data = theData; }
    void setNextLink(DoublyLinkedIntNode *pointer) { nextLink = pointer; }
    void setPreviousLink(DoublyLinkedIntNode *pointer) { previousLink = pointer; }

private:
    int data;
    DoublyLinkedIntNode *nextLink;
    DoublyLinkedIntNode *previousLink;
}

// FUNCTION DECLARATION
void
headInsert(DoublyLinkedIntNode &head, int theData);
//Precondition: The pointer variable head points to
//the head of a linked list.
//Postcondition: A new node containing theData
//has been added at the head of the linked list.

// FUNCTION DEFINITION
void headInsert(DoublyLinkedIntNodePtr &head, int theData)
{
    DoublyLinkedIntNode *newHead = new DoublyLinkedIntNode(theData, nullptr, head);
    head->setPreviousLink(newHead);
    head = newHead;
}

// FUNCTION DECLARATION
void deleteNode(DoublyLinkedIntNodePtr &head,
                DoublyLinkedIntNodePtr discard);
//Precondition: The pointer variable head points to
//the head of a linked list and discard points to the node to remove.
//Postcondition: The node pointed to by discard is removed from the list.

// FUNCTION DEFINITION
void deleteNode(DoublyLinkedIntNodePtr &head,
                DoublyLinkedIntNodePtr discard);
{
    if (head == discard)
    {
        head = head->getNextLink();
        head->setPreviousLink(nullptr);
    }
    else
    {
        DoublyLinkedIntNodePtr prev = discard->getPreviousLink();
        DoublyLinkedIntNodePtr next = discard->getNextLink();
        prev->setNextLink(next);
        if (next != nullptr)
        {
            next->setPreviousLink(prev);
        }
    }
    delete discard;
}