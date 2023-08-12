#include <iostream>

#include "heap.h"
using namespace std;

int main() {
    Heapp h;
    h.insert(3);
    h.insert(9);
    h.insert(2);
    h.insert(1);
    h.insert(4);
    h.insert(5);
    h.insert(6);

    h.max_heapify();
    // h.delete_node(9);
    h.max_heapify();
    h.print_heap();

    h.min_heapify();
    h.print_heap();
}