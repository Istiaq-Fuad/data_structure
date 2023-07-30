#include <iostream>

#include "bstree.h"

using namespace std;

int main() {
    bstree bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(2);
    bst.insert(9);
    bst.insert(7);
    bst.insert(12);
    bst.insert(4);
    bst.insert(11);
    bst.insert(8);
    bst.insert(1);
    bst.insert(3);

    bst.tree_sorted();
    cout << '\n';
    bst.delete_node(5);
    bst.tree_sorted();
    // cout << bst.iterative_search(5)->lchild->data << '\n';
}