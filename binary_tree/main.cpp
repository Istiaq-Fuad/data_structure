#include <iostream>

#include "tree.h"

using namespace std;

int main() {
    Tree btree;
    btree.insert(5);
    btree.insert(6);
    btree.insert(2);
    btree.insert(9);
    btree.insert(7);
    btree.insert(12);
    // btree.insert(4);
    // btree.insert(11);
    // btree.insert(8);
    // btree.insert(1);
    // btree.insert(3);

    btree.postorder();
    cout << '\n';
    btree.postorder();
}