#include "bstree.h"

#include <queue>
#include <stack>

using namespace std;

void bstree::destroy_tree(Node *root) {
    if (root != nullptr) {
        destroy_tree(root->lchild);
        destroy_tree(root->rchild);
        delete root;
    }
}