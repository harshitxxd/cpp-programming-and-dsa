#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n * 2^n)
class Solution {
public:
    void allsubset(vector<int>& nums, vector<int>& ans, int i,
                   vector<vector<int>>& subset) {
        if (i == static_cast<int>(nums.size())) {
            subset.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        allsubset(nums, ans, i + 1, subset);

        ans.pop_back();
        allsubset(nums, ans, i + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ans;

        allsubset(nums, ans, 0, subset);
        return subset;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> subsets1 = sol.subsets(nums1);
    cout << "Example 1 -> ";
    for (const vector<int>& subset : subsets1) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            if (i > 0) {
                cout << ", ";
            }
            cout << subset[i];
        }
        cout << "] ";
    }
    cout << '\n';

    vector<int> nums2 = {0};
    vector<vector<int>> subsets2 = sol.subsets(nums2);
    cout << "Example 2 -> ";
    for (const vector<int>& subset : subsets2) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            if (i > 0) {
                cout << ", ";
            }
            cout << subset[i];
        }
        cout << "] ";
    }
    cout << '\n';

    return 0;
}
