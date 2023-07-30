#ifndef TREE_H
#define TREE_H

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

class Tree {
   private:
    Node *root;
    void preorder(Node *p) const;
    void preorder_stack(Node *p) const;
    void inorder(Node *p) const;
    void inorder_stack(Node *p) const;
    void postorder(Node *p) const;
    void postorder_stack(Node *p) const;
    void levelorder(Node *p) const;
    void destroy_tree(Node *p);
    int count_node(Node *p) const;

   public:
    Tree() : root(nullptr){};
    ~Tree() { destroy_tree(root); };
    void insert(int key);
    void preorder() const { preorder(root); };
    void preorder_stack() const { preorder_stack(root); };
    void inorder() const { inorder(root); };
    void inorder_stack() const { inorder_stack(root); };
    void postorder() const { postorder(root); };
    void postorder_stack() const { postorder_stack(root); };
    void levelorder() const { levelorder(root); };
    int count_node() const { count_node(root); };
};

#endif