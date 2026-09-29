/*
 * File: four_sum.cpp
 * Topic: Arrays
 * Description: Finds all unique quadruplets that sum to the target.
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n;) {
                int p = j + 1, q = n - 1;

                while (p < q) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j]
                                  + nums[p] + nums[q];

                    if (sum < target) {
                        p++;
                    } else if (sum > target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        while (p < q && nums[p] == nums[p - 1]) {
                            p++;
                        }
                    }
                }

                j++;
                while (j < n && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result1 = sol.fourSum(nums1, 0);
    cout << "Example 1 -> ";
    for (const vector<int>& quadruplet : result1) {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", "
             << quadruplet[2] << ", " << quadruplet[3] << "] ";
    }
    cout << '\n';

    vector<int> nums2 = {2, 2, 2, 2, 2};
    vector<vector<int>> result2 = sol.fourSum(nums2, 8);
    cout << "Example 2 -> ";
    for (const vector<int>& quadruplet : result2) {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", "
             << quadruplet[2] << ", " << quadruplet[3] << "] ";
    }
    cout << '\n';

    return 0;
}
