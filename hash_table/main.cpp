#include <iostream>

#include "hash_table.cpp"

using namespace std;

int main() {
    HashTable ht(5);

    // linear probing
    ht.linear_insert(5);
    ht.linear_insert(11);
    ht.linear_insert(10);
    ht.linear_insert(14);

    ht.print_table();
    cout << '\n';

    int index = ht.linear_search(10);
    if (index == -1)
        cout << "10 not found" << '\n';
    else
        cout << "10 found at index " << index << '\n';

    // chaining
    cout << '\n';
    ht.chaining_insert(5);
    ht.chaining_insert(11);
    ht.chaining_insert(10);
    ht.chaining_insert(14);
    ht.chaining_insert(16);

    ht.print_chaining_table();

    if (ht.chaining_search(10))
        cout << "found" << '\n';
    else
        cout << "not found" << '\n';
}