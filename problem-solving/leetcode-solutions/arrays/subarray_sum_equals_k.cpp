/*
 * File: subarray_sum_equals_k.cpp
 * Topic: Arrays
 * Description: Counts non-empty subarrays whose sum equals k.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) {
                count++;
            }

            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            if (m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1};
    cout << "Example 1 -> " << sol.subarraySum(nums1, 2) << '\n';

    vector<int> nums2 = {1, 2, 3};
    cout << "Example 2 -> " << sol.subarraySum(nums2, 3) << '\n';

    return 0;
}
