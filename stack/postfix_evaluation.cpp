#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

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

string infix_to_postfix(string infix) {
    int size = infix.length();
    Stack<char> s(size);
    string postfix = "";

    for (int i = 0; i < size; i++) {
        char ch = infix[i];
        if (ch == ' ') continue;
        if (isdigit(ch) || (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')) {
            postfix += ch;
            int j = i + 1;
            while (isdigit(infix[j])) {
                postfix += infix[j];
                j++;
            }
            i = j - 1;
            postfix += ' ';
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (s.peek() != '(') {
                postfix += s.peek();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && get_precedence(ch) <= get_precedence(s.peek())) {
                postfix += s.peek();
                postfix += ' ';
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.peek();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int evaluate_postfix(string postfix) {
    int size = postfix.length();
    Stack<int> digits(size);

    for (int i = 0; i < size; i++) {
        char ch = postfix[i];
        if (ch == ' ') continue;

        if (isdigit(ch)) {
            int digit = ch - '0';
            int j = i + 1;
            while (isdigit(postfix[j])) {
                digit = (digit * 10) + (postfix[j] - '0');
                j++;
            }
            i = j - 1;
            digits.push(digit);
        } else if (is_operator(ch)) {
            int b = digits.peek();
            digits.pop();
            int a = digits.peek();
            digits.pop();

            int ans = operate(a, b, ch);
            digits.push(ans);
        } else if ((ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')) {
            int temp;
            cout << "value of " << ch << ": ";
            cin >> temp;
            digits.push(temp);
        }
    }

    return digits.peek();
}

int main() {
    string postfix;
    string infix;
    int ans;
    getline(cin, infix);

    postfix = infix_to_postfix(infix);
    ans = evaluate_postfix(postfix);

    cout << postfix << '\n';
    cout << ans << '\n';
}

// infix = A*B-(C+D)+E   ->   postfix = AB*CD+-E+
// infix = 2 * (5 * (3 + 6)) / 5 - 2   ->   2 5 3 6 + * * 5 / 2 -