#ifndef HASH_TABLE_H
#define HASH_TABLE_H

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class HashTable {
   private:
    int size;
    int length;
    int* data;
    Node** c_data;
    int linear_probing(int key);
    int quadratic_probing(int key);

   public:
    HashTable(int size);
    ~HashTable();
    void linear_insert(int key);
    int linear_search(int key);
    void quadratic_insert(int key);
    int quadratic_search(int key);
    void chaining_insert(int key);
    bool chaining_search(int key);
    void print_table() const;
    void print_chaining_table() const;
};

#endif