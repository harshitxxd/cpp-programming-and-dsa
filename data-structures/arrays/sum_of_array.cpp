/*
 * File: sum_of_array.cpp
 * Description: This program adds all elements of an array and prints the total sum.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
int sumofarr(int arr[], int sz) {
    int sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {4, 2, 7, 8, 1, 5};
    int sz = 6;
    cout << sumofarr(arr, sz);
    return 0;
}
