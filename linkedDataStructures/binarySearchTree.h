#ifndef tree_h
#define tree_h

namespace TreeBfost
{
    template <class T>
    class BinarySearchTree; //forward declaration

    template <class T>
    class TreeNode
    {
    public:
        TreeNode() {}
        TreeNode(T theData, TreeNode<T>* left, TreeNode<T>* right)
            : data(theData), leftLink(left), rightLink(right) {}
        friend class BinarySearchTree<T>;
    private:
        T data;
        TreeNode<T> *leftLink;
        TreeNode<T> *rightLink;
    };

    template <class T>
    class BinarySearchTree
    {
    // this is simplified, without copy ctr, overloaded operators, etc.
    public:
        BinarySearchTree() : root(nullptr) {}
        virtual ~BinarySearchTree();
        void insert (T item);
        bool inTree(T item) const;
        void inOrdershow() const;
    private:
        void insert(T item, TreeNode<T>*& subTreeRoot);
        bool inTree(T item, TreeNode<T>*& subTreeRoot) const;
        void deleteSubTree(TreeNode<T>*& subTreeRoot);
        void inOrderShow(TreeNode<T>*& subTreeRoot) const;
        TreeNode<T> *root;
    };
}

#endif //tree_h