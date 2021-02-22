#include <string>
#include "linkedlist.h"
#include "hashtable.h"

using LinkedListBfost::headInsert;
using LinkedListBfost::Node;
using LinkedListBfost::search;
using std::string;

namespace HashTableBfost
{
    HashTable::HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            hashArray[i] = nullptr;
        }
    }

    HashTable::~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node<string> *next = hashArray[i];
            while (next != nullptr)
            {
                Node<string> *discard = next;
                next = next->getLink();
                delete discard;
            }
        }
    }

    bool HashTable::containsString(string target) const
    {
        int hash = computeHash(target);
        return (search(hashArray[hash], target) == nullptr);
    }

    void HashTable::put(string s)
    {
        int hash = computeHash(s);
        if (search(hashArray[hash], s) == nullptr)
        {
            // only add target if it's not in the list
            headInsert(hashArray[hash], s);
        }
    }

    int HashTable::computeHash(string s)
    {
        int hash = 0;
        for (int i = 0; i < s.length(); i++)
        {
            hash += s[i];
        }

        return hash % SIZE;
    }
}