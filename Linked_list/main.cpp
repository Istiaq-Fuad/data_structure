#include <iostream>

#include "linked_list.h"

using namespace std;

int main() {
    LinkedList ll;
    ll.insert(2);
    ll.insert(1);
    ll.insert(6);
    ll.insert(4);

    // ll.insert_at(3, 4);
    // ll.delete_at(2);

    // Node* temp = ll.search(2);
    // cout << temp->data << '\n';

    ll.sort();
    ll.print_list();
}