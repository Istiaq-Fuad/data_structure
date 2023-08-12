#include "heap.h"

#include <iostream>
#include <utility>  // for using the swap function
using namespace std;

void Heapp::destroy_heap(int* heap) {
    if (heap != nullptr) {
        delete heap;
    }
}

void Heapp::insert(int key) {
    if (size == 0) {
        size += 1;
        heap = new int[size];
        heap[size - 1] = key;
        return;
    }

    size += 1;
    int* new_heap = new int[size];

    for (int i = 0; i < size - 1; i++) new_heap[i] = heap[i];
    new_heap[size - 1] = key;
    heap = new_heap;
}

void Heapp::heapify(int i, bool max_heap) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    // for max heap
    if (left < size && heap[left] > heap[largest] && max_heap)
        largest = left;
    if (right < size && heap[right] > heap[largest] && max_heap)
        largest = right;

    // for min heap
    if (left < size && heap[left] < heap[largest] && !max_heap)
        largest = left;
    if (right < size && heap[right] < heap[largest] && !max_heap)
        largest = right;

    if (largest != i) {
        swap(heap[largest], heap[i]);
        heapify(largest, max_heap);
    }
}

void Heapp::max_heapify() {
    for (int i = size / 2 - 1; i >= 0; i--) heapify(i, 1);
}

void Heapp::min_heapify() {
    for (int i = size / 2 - 1; i >= 0; i--) heapify(i, 0);
}

void Heapp::delete_node(int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i] == element) break;
    }

    if (i == size) {
        cout << "index out of bound" << '\n';
        return;
    }

    swap(heap[i], heap[size - 1]);
    // delete &heap[size - 1];
    size--;
}

void Heapp::print_heap() const {
    for (int i = 0; i < size; i++) cout << heap[i] << ' ';
    cout << '\n';
}