#ifndef BSTREE_H
#define BSTREE_H

class Node {
   public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(int data) {
        this->data = data;
        this->lchild = this->rchild = nullptr;
    }
};

class bstree {
   private:
    Node *root;
    void destroy_tree(Node *p);

   public:
    bstree() : root(nullptr){};
    ~bstree() { destroy_tree(root); };
};

#endif