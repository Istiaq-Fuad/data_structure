#include "bstree.h"

#include <iostream>
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

void bstree::inorder(Node *root) const {
    if (root == nullptr) return;

    inorder(root->lchild);
    cout << root->data << '\t';
    inorder(root->rchild);
}

Node *bstree::recursive_search(Node *root, int key) const {
    if (root == nullptr) return nullptr;
    if (root->data == key) return root;

    if (key < root->data)
        return recursive_search(root->lchild, key);
    else
        return recursive_search(root->rchild, key);
}

Node *bstree::iterative_search(Node *root, int key) const {
    Node *temp = root;
    while (temp != nullptr) {
        if (key == temp->data)
            return temp;
        else if (key > temp->data)
            temp = temp->rchild;
        else
            temp = temp->lchild;
    }

    return nullptr;
}

void bstree::insert(Node *root, int key) {
    if (root == nullptr) {
        this->root = new Node(key);
        return;
    }

    Node *new_node = new Node(key);
    Node *temp = root;
    Node *prev = root;
    while (temp != nullptr) {
        if (key == temp->data) {
            cout << "duplicate key can't be inserted" << '\n';
            return;
        }

        prev = temp;

        if (key > temp->data)
            temp = temp->rchild;
        else
            temp = temp->lchild;
    }

    if (key > prev->data)
        prev->rchild = new_node;
    else if (key < prev->data)
        prev->lchild = new_node;
}

