#include "tree.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Tree::Tree() : root(nullptr) {}

void Tree::destroy_tree(Node *root) {
    if (root != nullptr) {
        destroy_tree(root->lchild);
        destroy_tree(root->rchild);
        delete root;
    }
}

void Tree::insert(int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->lchild == nullptr) {
            temp->lchild = new Node(data);
            return;
        }

        if (temp->rchild == nullptr) {
            temp->rchild = new Node(data);
            return;
        }

        q.push(temp->lchild);
        q.push(temp->rchild);
    }
}

void Tree::preorder(Node *root) const {
    if (root == nullptr) return;

    cout << root->data << '\t';
    preorder(root->lchild);
    preorder(root->rchild);
}

void Tree::postorder(Node *root) const {
    if (root == nullptr) return;

    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << '\t';
}

void Tree::inorder(Node *root) const {
    if (root == nullptr) return;

    inorder(root->lchild);
    cout << root->data << '\t';
    inorder(root->rchild);
}

void Tree::levelorder(Node *root) const {
    if (root == nullptr) return;

    cout << root->data << '\t';

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->lchild != nullptr) {
            cout << temp->lchild->data << '\t';
            q.push(temp->lchild);
        }

        if (temp->rchild != nullptr) {
            cout << temp->rchild->data << '\t';
            q.push(temp->rchild);
        }
    }
}

void Tree::preorder_stack(Node *root) const {
    if (root == nullptr) return;

    stack<Node *> s;

    Node *temp = root;
    while (!s.empty() || temp != nullptr) {
        if (temp == nullptr) temp = s.top(), s.pop();

        cout << temp->data << '\t';
        if (temp->rchild != nullptr) s.push(temp->rchild);
        temp = temp->lchild;
    }
}

void Tree::inorder_stack(Node *root) const {
    if (root == nullptr) return;

    stack<Node *> s;

    Node *temp = root;
    while (!s.empty() || temp != nullptr) {
        if (temp != nullptr) {
            s.push(temp);
            temp = temp->lchild;
        } else {
            temp = s.top();
            s.pop();

            cout << temp->data << '\t';
            temp = temp->rchild;
        }
    }
}

void Tree::postorder_stack(Node *root) const {
    if (root == nullptr) return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty()) {
        auto temp = s1.top();
        s2.push(temp);
        s1.pop();

        if (temp->lchild != nullptr) s2.push(temp->lchild);
        if (temp->rchild != nullptr) s2.push(temp->rchild);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << '\t';
        s2.pop();
    }
}