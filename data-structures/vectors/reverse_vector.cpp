/*
 * File: reverse_vector.cpp
 * Description: This program reverses the elements of a vector and prints the result.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
void reverse(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int main() {
    vector<int> mynums = {10, 20, 30, 40, 50};
    reverse(mynums);

    cout << "reversed vector: ";
    for (int i = 0; i < mynums.size(); i++) {
        cout << mynums[i] << " ";
    }
    cout << '\n';
    return 0;
}
