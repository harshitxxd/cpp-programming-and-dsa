/*
 * File: unique_elements.cpp
 * Description: This program identifies and prints the unique values present in an array.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n^2)
void unique(int arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        int count = 0;
        for (int j = 0; j < sz; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    unique(arr, sz);
    return 0;
}
