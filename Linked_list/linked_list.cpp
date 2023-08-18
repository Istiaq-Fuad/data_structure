#include "linked_list.h"

#include <iostream>
using namespace std;

LinkedList::~LinkedList() {
    Node* current = this->root;
    while (current != nullptr) {
        Node* temp = current;
        current = temp->next;
        delete temp;
    }
}

Node* LinkedList::create_node(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void LinkedList::insert(int data) {
    Node* new_node = create_node(data);

    if (root == nullptr) {
        root = new_node;
        return;
    }

    Node* temp = root;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = new_node;
}

void LinkedList::insert_at(int data, int pos) {
    Node* new_node = create_node(data);
    if (root == nullptr || pos == 1) {
        new_node->next = root;
        root = new_node;
    }

    Node* temp1 = root;
    pos -= 2;
    while (pos--) temp1 = temp1->next;

    Node* temp2 = temp1->next;
    temp1->next = new_node;
    new_node->next = temp2;
}

void LinkedList::delete_first() {
    if (root == nullptr) return;

    Node* temp = root;
    root = root->next;
    delete temp;
}

void LinkedList::delete_last() {
    if (root == nullptr) return;

    if (root->next == nullptr) {
        Node* temp = root;
        root = nullptr;
        delete temp;
        return;
    }

    Node* temp1 = root;
    Node* temp2 = temp1;
    while (temp1->next != nullptr) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = nullptr;
    delete temp1;
}

void LinkedList::delete_at(int pos) {
    if (root == nullptr) return;

    if (pos == 1) {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }

    Node* temp1 = root;
    Node* temp2 = temp1;
    pos--;
    while (pos--) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
}

Node* LinkedList::search(int data) const {
    if (root == nullptr) return nullptr;

    Node* temp = root;
    while (temp->data != data && temp != nullptr)
        temp = temp->next;

    return temp;
}

void LinkedList::sort() {
    if (root == nullptr) return;

    Node* temp = root;

    while (temp != nullptr) {
        Node* temp2 = temp->next;
        while (temp2 != nullptr) {
            if (temp2->data < temp->data) {
                int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void LinkedList::print_list() const {
    Node* temp = root;
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << '\n';
}