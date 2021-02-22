#include <iostream>
#include "binarySearchTree.h"

namespace TreeBfost
{
    template <class T>
    void BinarySearchTree<T>::insert(T item, TreeNode<T>*& subTreeRoot)
    {
        if (subTreeRoot == nullptr)
        {
            subTreeRoot = new TreeNode<T>(item, nullptr, nullptr);
        }
        else if (item < subTreeRoot->data)
        {
            insert (item, subTreeRoot->leftLink);
        }
        else // item >= subTreeRoot->data
        {
            insert(item, subTreeRoot->rightLink);
        }
    }

    template <class T>
    void BinarySearchTree<T>::insert (T item)
    {
        insert(item, root);
    }

    template <class T>
    bool BinarySearchTree<T>::inTree(T item, TreeNode<T>*& subTreeRoot) const
    {
        if (subTreeRoot == nullptr)
        {
            return false;
        }
        else if (subTreeRoot->data == item)
        {
            return true;
        }
        else if (item < subTreeRoot->data)
        {
            return inTree(item, subTreeRoot->leftLink);
        }
        else // item >- subTreeRoot->data
        {
            return inTree(item, subTreeRoot->rightLink);
        }
    }

    template <class T>
    bool BinarySearchTree<T>::inTree(T item) const
    {
        return inTree(item, root);
    }

    template <class T>
    void BinarySearchTree<T>::inOrderShow(TreeNode<T>*& subTreeRoot) const
    {
        if (subTreeRoot != nullptr)
        {
            // in-order traversal of tree...leftSub, root, rightSub
            inOrderShow(subTreeRoot->leftLink);
            std::cout << subTreeRoot->data << " ";
            inOrderShow(subTreeRoot->rightLink);
        }
    }

    template <class T>
    void BinarySearchTree<T>::inOrdershow() const
    {
        inOrderShow(root);
    }

    template <class T>
    void BinarySearchTree<T>::deleteSubTree(TreeNode<T>*& subTreeRoot)
    {
        if (subTreeRoot != nullptr)
        {
            // post-order traversal of tree ... leftSub, rightSub, root
            deleteSubTree(subTreeRoot->leftLink);
            deleteSubTree(subTreeRoot->rightLink);
            //subTreeRoot now points to a one-node tree
            delete subTreeRoot;
            subTreeRoot = nullptr;
        }
    }

    template <class T>
    BinarySearchTree<T>::~BinarySearchTree()
    {
        deleteSubTree(root); 
    }
}