#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n * 2^n)
    // Each recursion level explores the next index, and the skip loop only skips duplicates.
    void getallsubset(vector<int>& nums, vector<int>& ans, int i,
                      vector<vector<int>>& subset) {
        if (i == static_cast<int>(nums.size())) {
            subset.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getallsubset(nums, ans, i + 1, subset);

        ans.pop_back();
        int idx = i + 1;
        while (idx < static_cast<int>(nums.size()) && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        getallsubset(nums, ans, idx, subset);
    }

    // Time Complexity: O(n * 2^n)
    // Sorting takes O(n log n), and generating all unique subsets takes O(n * 2^n) overall.
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> subset;
        vector<int> ans;

        getallsubset(nums, ans, 0, subset);
        return subset;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> examples = {{1, 2, 2}, {0}};
    for (size_t i = 0; i < examples.size(); i++) {
        vector<vector<int>> subsets = sol.subsetsWithDup(examples[i]);
        cout << "Example " << i + 1 << " -> ";
        for (const vector<int>& subset : subsets) {
            cout << "[";
            for (size_t j = 0; j < subset.size(); j++) {
                if (j > 0) {
                    cout << ", ";
                }
                cout << subset[j];
            }
            cout << "] ";
        }
        cout << '\n';
    }

    return 0;
}