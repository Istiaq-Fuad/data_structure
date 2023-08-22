#include <iostream>

using namespace std;

void tower_of_hanoi(int n, char from, char helper, char to) {
    if (n == 0) return;
    
    tower_of_hanoi(n - 1, from, to, helper);
    cout << "move the disk from " << from << " to " << to << '\n';
    tower_of_hanoi(n - 1, helper, from, to);
}

int main() {
    tower_of_hanoi(3, 'A', 'B', 'C');
}