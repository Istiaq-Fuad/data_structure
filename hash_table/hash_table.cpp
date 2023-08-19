#include "hash_table.h"

#include <iostream>

using namespace std;

HashTable::HashTable(int size) {
    this->size = size;
    length = 0;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = -1;

    // for chaining table
    c_data = new Node*[size];
    for (int i = 0; i < size; i++) c_data[i] = nullptr;
}

HashTable::~HashTable() {
    delete[] data;

    // deleting chaining table
    for (int i = 0; i < size; i++) {
        Node* p = c_data[i];
        while (c_data[i]) {
            c_data[i] = c_data[i]->next;
            delete p;
            p = c_data[i];
        }
    }
    delete[] c_data;
}

int HashTable::linear_probing(int key) {
    int initial_hash = key % size;

    int i = 0;
    int hash = initial_hash;
    while (data[hash] != -1) {
        i++;
        hash = (initial_hash + i) % size;
    }

    return hash;
}

void HashTable::linear_insert(int key) {
    if (length == size) {
        cout << "hashtable is full" << '\n';
        return;
    }

    int hash = linear_probing(key);
    data[hash] = key;
}

int HashTable::linear_search(int key) {
    int initial_hash = key % size;
    if (data[initial_hash] == key) return initial_hash;

    int i = 0;
    int hash = initial_hash + 1;
    while (data[hash] != key) {
        if (data[hash] == -1 || hash == initial_hash) return -1;

        i++;
        hash = (initial_hash + i) % size;
    }

    return hash;
}

int HashTable::quadratic_probing(int key) {
    int initial_hash = key % size;

    int i = 0;
    int hash = initial_hash;
    while (data[hash] != -1) {
        i++;
        hash = (initial_hash + i * i) % size;
    }

    return hash;
}

void HashTable::quadratic_insert(int key) {
    if (length == size) {
        cout << "hashtable is full" << '\n';
        return;
    }

    int hash = quadratic_probing(key);
    data[hash] = key;
}

int HashTable::quadratic_search(int key) {
    int initial_hash = key % size;
    if (data[initial_hash] == key) return initial_hash;

    int i = 0;
    int hash = initial_hash + 1;
    while (data[hash] != key) {
        if (data[hash] == -1 || hash == initial_hash) return -1;

        i++;
        hash = (initial_hash + i * i) % size;
    }

    return hash;
}

void HashTable::chaining_insert(int key) {
    int hash = key % size;
    Node* new_node = new Node(key);

    if (c_data[hash] == nullptr) {
        c_data[hash] = new_node;
        return;
    }

    Node* temp = c_data[hash];
    while (temp->next != nullptr) temp = temp->next;

    temp->next = new_node;
}

bool HashTable::chaining_search(int key) {
    int hash = key % size;

    if (c_data[hash] == nullptr) return false;

    Node* temp = c_data[hash];
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void HashTable::print_table() const {
    for (int i = 0; i < size; i++)
        if (data[i] != -1) cout << data[i] << " at index " << i << '\n';
}

void HashTable::print_chaining_table() const {
    for (int i = 0; i < size; i++) {
        if (c_data[i] == nullptr) continue;

        Node* temp = c_data[i];
        while (temp != nullptr) {
            cout << temp->data << " at index " << i << '\n';
            temp = temp->next;
        }
    }
}