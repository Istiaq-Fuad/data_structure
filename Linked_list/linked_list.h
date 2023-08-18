#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
   private:
    Node* root;
    Node* create_node(int data);

   public:
    LinkedList() : root(nullptr){};
    ~LinkedList();
    void insert(int data);
    void insert_at(int data, int pos);
    void delete_first();
    void delete_last();
    void delete_at(int pos);
    Node* search(int data) const;
    void sort();
    void print_list() const;
};

#endif