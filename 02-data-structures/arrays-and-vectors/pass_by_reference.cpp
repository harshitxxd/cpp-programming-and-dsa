/*
 * File: pass_by_reference.cpp
 * Description: This program demonstrates passing variables by reference so changes inside a function affect the original values.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)

void changearr(int arr[], int size) {
    cout << "in function\n";
    for (int i = 0; i < size; i++) {
        arr[i] = 2 * arr[i];
        cout << arr[i] << " \n";
    }
}

int main() {
    int arr[] = {1, 2, 3};
    changearr(arr, 3);

    cout << "in main \n";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " \n";
    }
    return 0;
}
