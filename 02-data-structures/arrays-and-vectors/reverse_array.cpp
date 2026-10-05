/*
 * File: reverse_array.cpp
 * Description: This program reverses the elements of an array and prints the result.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
void reversearr(int arr[], int sz) {
    int start = 0, end = sz - 1;
    while (start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {4, 2, 7, 8, 1, 5};
    int sz = 6;
    reversearr(arr, sz);
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
