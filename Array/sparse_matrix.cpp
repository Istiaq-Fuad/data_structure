#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 1];

    for (int i = 1; i <= n; i++) cin >> arr[i];

    int r, c;
    cin >> r >> c;

    int index = (r * r - 1) / 2 + c;
    cout << arr[index];
}