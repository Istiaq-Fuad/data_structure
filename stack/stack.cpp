#include "stack.h"

#include <iostream>

using namespace std;

Stack::Stack(int size) {
    this->size = size;
    top = -1;
    elements = new int[size];
}

Stack::~Stack() {
    delete[] elements;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == size - 1;
}

void Stack::push(int data) {
    if (isFull()) {
        cout << "Stack is full" << '\n';
        return;
    }

    elements[++top] = data;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << '\n';
        return;
    }

    top--;
}

int Stack::peek() const {
    if (top == -1) {
        cout << "Stack is empty" << '\n';
        return -1;
    }
    return elements[top];
}

void Stack::print_stack() {
    int temp = top;
    while (temp != -1) {
        cout << elements[temp] << ' ';
        temp--;
    }

    cout << '\n';
}