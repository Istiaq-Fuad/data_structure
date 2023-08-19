#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {6, 2, 9, 3, 1, 5};
    int size = 6;

    bubble_sort(arr, size);

    for (int a : arr) cout << a << ' ';
    cout << '\n';
}