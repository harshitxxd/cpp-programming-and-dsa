/*
 * File: find_min_max.cpp
 * Description: This program finds the minimum and maximum values in an array.
 *
 */

#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(n)
int main() {
    int nums[] = {5, 15, 22, 1, -15, 24};
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int size = 6;

    for (int i = 0; i < size; i++) {
        smallest = min(nums[i], smallest);
        largest = max(nums[i], largest);
    }

    cout << "smallest = " << smallest << '\n';
    cout << "largest = " << largest << '\n';
    return 0;
}
   