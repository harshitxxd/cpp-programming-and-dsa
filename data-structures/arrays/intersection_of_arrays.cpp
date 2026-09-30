/*
 * File: intersection_of_arrays.cpp
 * Description: This program finds the common elements between two arrays.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
void intersection(int arr1[], int arr2[]) {
    int sz1 = 5, sz2 = 5;
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
            }
        }
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    intersection(arr1, arr2);
    return 0;
}
