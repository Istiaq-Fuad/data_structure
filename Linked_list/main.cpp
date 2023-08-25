#include <iostream>

#include "linked_list.h"

using namespace std;

int main() {
    LinkedList ll;
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(6);
    ll.insertAtEnd(4);
    ll.insertAtBeginning(9);
    // ll.insert_at(3, 4);
    // ll.delete_at(2);

    Node* temp = ll.search(3);
    if (temp == nullptr)
        cout << "element doesn't exist" << '\n';
    else
        cout << temp->data << '\n';

    // ll.sort();
    ll.print_list();
    ll.reverse();
    ll.print_list();
}