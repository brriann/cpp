#ifndef hashtable_h
#define hashtable_h

#include <string>
#include "linkedlist.h"

using LinkedListBfost::Node;
using std::string;

namespace HashTableBfost
{
    const int SIZE = 10;

    class HashTable
    {
    public:
        HashTable();
        // copy ctr... TODO
        // overloaded = operator ... TODO
        virtual ~HashTable();
        bool containsString(string target) const;
        void put(string s);
    private:
        Node<string> *hashArray[SIZE];
        static int computeHash(string s);
    };
}

#endif //hashtable_h