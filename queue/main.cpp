#include <iostream>

#include "queue.h"

using namespace std;

int main() {
    Queue q(10);
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');

    q.dequeue();

    q.print_queue();
}