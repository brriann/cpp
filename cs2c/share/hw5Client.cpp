//AVLTree::Print
// TODO, put this method in the public section of AVLTree class

// void print() {
//     if (root_ != nullptr) {
//         root_.get()->print();
//     }
// }

// Node::Print()
// TODO, put this method in the private section of Node class
// NOTE: this prints the tree out "backwards", so you can tilt your head to your left shoulder and "see" the tree in the console output.  
// maybe you want to flip the "left" and "right" sections, to print in a proper in-order traversal, i found this harder to visualize when looking at console output

// void print(int depth = 0) const {
//     if (right_ != nullptr) {
//     right_.get()->print(depth + 1);
//     }
//     for (int i = 0; i < depth; ++i) {
//     cout << "  ";
//     }
//     cout << key_ << ": " << value_ << " (bf: " << balance_factor_ << ")" << " (ht: " << height_ << ")" << endl;
//     if (left_ != nullptr) {
//     left_.get()->print(depth + 1);
//     }
// }



#include <string>
#include "avl_tree.h" // TODO, replace this with path to your avl_tree.h HW5 implementation
#include <algorithm>

using namespace std;

int main() {

   AVLTree<int> tree = AVLTree<int>();
   tree[3] = 33;
   tree[2] = 22;
   tree[1] = 11;
   tree[4] = 44;
   tree[5] = 55;
   tree[6] = 66;
   tree[7] = 77;
   tree[16] = 1616;
   tree[15] = 1515;
   tree[14] = 1414;
   tree[13] = 1313;
   tree[12] = 1212;
   tree[11] = 1111;
   tree[10] = 1010;
   tree[8] = 88;
   tree[9] = 99;
   tree.print();

   cout << tree[1] << " " << tree[2] << " " << tree[3];

   cout << endl << "AVLTree publics " << endl;
   cout << "size: " << tree.size() << endl;
   cout << "tree[12] : " << tree[12] << endl;

   cout << "Node publics " << endl;
   auto treeRoot = tree.root();
   cout << "balance_factor: " << treeRoot->balance_factor() << endl;
   cout << "key: " << treeRoot->key() << endl;
   cout << "value: " << treeRoot->value() << endl;

   auto treeRootLeft = treeRoot->left();
   cout << "balance_factor: " << treeRootLeft->balance_factor() << endl;
   cout << "key: " << treeRootLeft->key() << endl;
   cout << "value: " << treeRootLeft->value() << endl;

   auto treeRootRight = treeRoot->right();
   cout << "balance_factor: " << treeRootRight->balance_factor() << endl;
   cout << "key: " << treeRootRight->key() << endl;
   cout << "value: " << treeRootRight->value() << endl;

   AVLTree<char, string> tree2 = AVLTree<char, string>();

   tree2['k'] = "kkkk";
   tree2['g'] = "gggg";
   tree2['w'] = "wwww";
   tree2['a'] = "aaaa";
   tree2['v'] = "vvvv";
   tree2['c'] = "cccc";
   tree2['i'];// = "iiii";
   tree2['u'] = "uuuu";
   tree2['e'] = "eeee";
   tree2['o'] = "oooo";
   tree2['p'] = "pppp";
   tree2.print();

   cout << tree2['k'] << " " << tree2['e'] << " " << tree2['u'];

   cout << endl << "AVLTree publics " << endl;
   cout << "size: " << tree2.size() << endl;
   cout << "tree['i'] : " << tree2['i'] << endl;

   cout << "Node publics " << endl;
   auto tree2Root = tree2.root();
   cout << "balance_factor: " << tree2Root->balance_factor() << endl;
   cout << "key: " << tree2Root->key() << endl;
   cout << "value: " << tree2Root->value() << endl;

   auto treeRoot2Left = tree2Root->left();
   cout << "balance_factor: " << treeRoot2Left->balance_factor() << endl;
   cout << "key: " << treeRoot2Left->key() << endl;
   cout << "value: " << treeRoot2Left->value() << endl;

   auto treeRoot2Right = tree2Root->right();
   cout << "balance_factor: " << treeRoot2Right->balance_factor() << endl;
   cout << "key: " << treeRoot2Right->key() << endl;
   cout << "value: " << treeRoot2Right->value() << endl;

   //cout << 

   return 0;
}