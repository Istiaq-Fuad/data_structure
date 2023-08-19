#include <iostream>

#include "stack.h"

using namespace std;

int main() {
    Stack s(5);

    s.push(4);
    s.push(9);
    s.push(3);

    int data = s.peek();
    cout << data << '\n';
    s.print_stack();
}