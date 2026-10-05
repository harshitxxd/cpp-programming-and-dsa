#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    set<vector<int>> s;

    void getallcombination(vector<int>& arr, int idx, int target,
                           vector<vector<int>>& ans, vector<int>& combination) {
        if (target == 0) {
            if (s.find(combination) == s.end()) {
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }
        if (idx == static_cast<int>(arr.size()) || target < 0) {
            return;
        }

        combination.push_back(arr[idx]);
         getallcombination(arr, idx+1, target - arr[idx], ans, combination);
        getallcombination(arr, idx, target - arr[idx], ans, combination);
    
        combination.pop_back();

        getallcombination(arr, idx + 1, target, ans, combination);
    }

    // Time complexity: Exponential in the candidate count and target; each
    // unique combination is copied into the result.
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        s.clear();
        vector<vector<int>> ans;
        vector<int> combination;
        getallcombination(arr, 0, target, ans, combination);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> candidates = {{2, 3, 6, 7}, {2, 3, 5}, {2}};
    vector<int> targets = {7, 8, 1};

    for (size_t i = 0; i < candidates.size(); i++) {
        vector<vector<int>> combinations =
            sol.combinationSum(candidates[i], targets[i]);
        cout << "Example " << i + 1 << " -> ";
        for (const vector<int>& combination : combinations) {
            cout << "[";
            for (size_t j = 0; j < combination.size(); j++) {
                if (j > 0) {
                    cout << ", ";
                }
                cout << combination[j];
            }
            cout << "] ";
        }
        if (combinations.empty()) {
            cout << "[]";
        }
        cout << '\n';
    }

    return 0;
}
