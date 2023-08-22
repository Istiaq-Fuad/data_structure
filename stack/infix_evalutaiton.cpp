#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int operate(int a, int b, char o) {
    if (o == '+')
        return (a + b);
    else if (o == '-')
        return (a - b);
    else if (o == '*')
        return (a * b);
    else if (o == '/')
        return (a / b);
    else if (o == '^')
        return pow(a, b);
    else
        return 0;
}

int get_precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
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
            while (isdigit(infix[j])) {
                digit = (digit * 10) + (infix[j] - '0');
                j++;
            }
            i = j - 1;
            operand.push(digit);
        } else if (is_operator(infix[i])) {
            if (operators.isEmpty())
                operators.push(infix[i]);
            else if (get_precedence(infix[i]) >= get_precedence(operators.peek()))
                operators.push(infix[i]);
            else if (get_precedence(infix[i]) < get_precedence(operators.peek())) {
                while (get_precedence(infix[i]) < get_precedence(operators.peek())) {
                    int b = operand.peek();
                    operand.pop();
                    int a = operand.peek();
                    operand.pop();
                    char o = operators.peek();
                    operators.pop();

                    int ans = operate(a, b, o);
                    operand.push(ans);

                    if (operators.isEmpty()) break;
                }
                operators.push(infix[i]);
            }
        } else if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (operators.peek() != '(') {
                int b = operand.peek();
                operand.pop();
                int a = operand.peek();
                operand.pop();
                char o = operators.peek();
                operators.pop();

                int ans = operate(a, b, o);
                operand.push(ans);
            }
            operators.pop();
        }
    }

    while (!operators.isEmpty()) {
        int b = operand.peek();
        operand.pop();
        int a = operand.peek();
        operand.pop();
        char o = operators.peek();
        operators.pop();

        int ans = operate(a, b, o);
        operand.push(ans);
    }

    return operand.peek();
}

int main() {
    string infix;
    getline(cin, infix);

    int ans = evaluate_infix(infix);
    cout << ans << '\n';
}