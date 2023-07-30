#include <iostream>

#include "bstree.h"

using namespace std;

int main() {
    bstree bst;
    bst.insert(5);
    bst.insert(2);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);

    bst.tree_sorted();
    cout << '\n';
    cout << bst.iterative_search(5)->lchild->data << '\n';
}