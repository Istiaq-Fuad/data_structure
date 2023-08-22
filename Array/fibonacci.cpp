#include <iostream>

using namespace std;

int fib(int a) {
    if (a == 1) return 0;
    if (a == 2) return 1;

    return fib(a - 1) + fib(a - 2);
}

int main() {
    int n;
    cout << "enter a number: ";
    cin >> n;

    cout << n << "th fibonacci number is " << fib(n);
}