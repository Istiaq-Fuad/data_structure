#include "queue.h"

#include <iostream>

using namespace std;

Queue::Queue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    this->data = new char[size];
}

Queue::~Queue() {
    delete[] data;
}

bool Queue::isEmpty() const {
    return front == rear;
}

bool Queue::isFull() const {
    return (rear + 1) % size == front;
}

void Queue::enqueue(char element) {
    if (isFull()) {
        cout << "queue is full" << '\n';
        return;
    }

    rear = (rear + 1) % size;
    data[rear] = element;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "queue is empty" << '\n';
        return;
    }

    front = (front + 1) % size;
}

char Queue::front_element() const {
    if (isEmpty()) {
        cout << "queue is empty" << '\n';
        return ' ';
    }

    int temp = (front + 1) % size;
    return data[temp];
}

void Queue::print_queue() const {
    if (isEmpty()) {
        cout << "queue is empty" << '\n';
        return;
    }

    int temp = (front + 1) % size;
    while (temp <= rear) {
        cout << data[temp] << ' ';
        temp = (temp + 1) % size;
    }
    cout << '\n';
}