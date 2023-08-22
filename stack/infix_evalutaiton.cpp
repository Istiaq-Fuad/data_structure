#include <cctype>
#include <iostream>
// #include <stack>

#include "stack.cpp"

using namespace std;

int get_precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 1;
    else if (op == '+' || op == '-')
        return 1;
}

int evaluate_infix(string infix) {
    int size = infix.length();
    Stack<char> operators(size);
    Stack<int> operand(size);

    for (int i = 0; i < size; i++) {
        if (infix[i] == ' ')
            continue;
        else if (isdigit(infix[i])) {
            int digit = infix[i] - '0';
            int j = i + 1;
            while (!isdigit(infix[i])) {
                digit = (digit * 10) + (infix[i] - '0');
                j++;
            }
            i = j - 1;
            operand.push(digit);
        }
    }
}

int main() {
}