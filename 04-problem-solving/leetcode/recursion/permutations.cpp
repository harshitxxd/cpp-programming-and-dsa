#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getpermutation(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == static_cast<int>(nums.size())) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < static_cast<int>(nums.size()); i++) {
            swap(nums[idx], nums[i]);
            getpermutation(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    // Time complexity: O(n * n!), including copying each permutation into the result.
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermutation(nums, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> examples = {{1, 2, 3}, {0, 1}, {1}};

    for (size_t i = 0; i < examples.size(); i++) {
        vector<vector<int>> permutations = sol.permute(examples[i]);
        cout << "Example " << i + 1 << " -> ";
        for (const vector<int>& permutation : permutations) {
            cout << "[";
            for (size_t j = 0; j < permutation.size(); j++) {
                if (j > 0) {
                    cout << ", ";
                }
                cout << permutation[j];
            }
            cout << "] ";
        }
        cout << '\n';
    }

    return 0;
}
