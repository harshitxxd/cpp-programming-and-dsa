/*
 * File: next_greater_element_ii.cpp
 * Description: Finds next greater values in a circular array using a
 *              monotonic stack.
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // Time complexity: O(n), since the doubled traversal pushes and pops each
    // index at most twice.
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }
            ans[i % n] = s.empty() ? -1 : nums[s.top()];
            s.push(i % n);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 1};
    vector<int> answer1 = sol.nextGreaterElements(nums1);
    cout << "Example 1 -> ";
    for (int value : answer1) {
        cout << value << ' ';
    }
    cout << '\n';

    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> answer2 = sol.nextGreaterElements(nums2);
    cout << "Example 2 -> ";
    for (int value : answer2) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
