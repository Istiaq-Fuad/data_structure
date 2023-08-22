#include <iostream>

#include "stack.h"

// using namespace std;

int main() {
    Stack<char> s(5);

    s.push('a');
    s.push('g');
    s.push('e');

    char data = s.peek();
    std::cout << data << '\n';
    s.print_stack();
}