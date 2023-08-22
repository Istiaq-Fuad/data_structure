#ifndef STACK_H
#define STACK_H

#include <iostream>
template <typename T>
class Stack {
   private:
    int size;
    int top;
    T* elements;

   public:
    Stack(int size);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(T data);
    void pop();
    T peek() const;
    void print_stack();
};

template <typename T>
Stack<T>::Stack(int size) {
    this->size = size;
    top = -1;
    elements = new T[size];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elements;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() const {
    return top == size - 1;
}

template <typename T>
void Stack<T>::push(T data) {
    if (isFull()) {
        std::cout << "Stack is full" << '\n';
        return;
    }

    elements[++top] = data;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << '\n';
        return;
    }

    top--;
}

template <typename T>
T Stack<T>::peek() const {
    if (top == -1) {
        std::cout << "Stack is empty" << '\n';
        return -1;
    }
    return elements[top];
}

template <typename T>
void Stack<T>::print_stack() {
    int temp = top;
    while (temp != -1) {
        std::cout << elements[temp] << ' ';
        temp--;
    }

    std::cout << '\n';
}

#endif