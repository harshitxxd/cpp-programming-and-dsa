/*
 * File: linear_search.cpp
 * Description: This program searches for a target value in an array and reports whether it exists.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
int linearsearch(int arr[], int sz, int target) {
    for (int i = 0; i < sz; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 8, 1, 5};
    int sz = 6;
    int target = 8;
    cout << linearsearch(arr, sz, target) << '\n';
    return 0;
}
