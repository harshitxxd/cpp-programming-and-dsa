/*
 * File: find_duplicate_number.cpp
 * Topic: Arrays
 * Description: Finds the repeated number without modifying the input array.
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Example 1 -> duplicate: " << sol.findDuplicate(nums1) << '\n';

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Example 2 -> duplicate: " << sol.findDuplicate(nums2) << '\n';

    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << "Example 3 -> duplicate: " << sol.findDuplicate(nums3) << '\n';

    return 0;
}
