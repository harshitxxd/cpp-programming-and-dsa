/*
 * File: three_sum.cpp
 * Topic: Arrays
 * Description: Finds all unique triplets in the array that sum to zero.
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> examples = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0},
    };

    for (size_t i = 0; i < examples.size(); i++) {
        vector<vector<int>> result = sol.threeSum(examples[i]);
        cout << "Example " << i + 1 << " -> ";
        for (const vector<int>& triplet : result) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", "
                 << triplet[2] << "] ";
        }
        if (result.empty()) {
            cout << "[]";
        }
        cout << '\n';
    }

    return 0;
}
