#ifndef BSTREE_H
#define BSTREE_H

class Node {
   public:
    Node* lchild;
    int data;
    Node* rchild;
    Node(int data) {
        this->data = data;
        this->lchild = this->rchild = nullptr;
    }
};

class bstree {
   private:
    Node* root;
    void destroy_tree(Node* p);
    Node* recursive_search(Node* p, int key) const;
    Node* iterative_search(Node* p, int key) const;
    void inorder(Node* p) const;
    void insert(Node* p, int key);

   public:
    bstree() : root(nullptr){};
    ~bstree() { destroy_tree(root); };
    void tree_sorted() const { inorder(root); };
    Node* recursive_search(int key) const { return recursive_search(root, key); };
    Node* iterative_search(int key) const { return iterative_search(root, key); };
    void insert(int key) { insert(root, key); };
    void delete_node(int key);
    // void levelorder() const;
};

#endif