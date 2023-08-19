#include <iostream>

using namespace std;

int binary_search(int arr[], int key, int size) {
    int beginning = 0;
    int end = size - 1;
    int mid = (beginning + end) / 2;

    while (beginning <= end && key != arr[mid]) {
        if (key > arr[mid])
            beginning = mid + 1;
        else
            end = mid - 1;
        mid = (beginning + end) / 2;
    }

    if (arr[mid] == key)
        return mid;
    else
        return -1;
}

int main() {
    int arr[] = {1, 3, 5, 6, 7, 9, 13, 20};
    int size = 8;

    int key;
    cout << "enter a number to search: ";
    cin >> key;

    int index = binary_search(arr, key, size);
    if (index == -1)
        cout << key << " not found" << '\n';
    else
        cout << key << " found at index " << index;
}