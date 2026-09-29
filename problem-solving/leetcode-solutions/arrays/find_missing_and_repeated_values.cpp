/*
 * File: find_missing_and_repeated_values.cpp
 * Topic: Arrays
 * Description: Finds the repeated and missing values in an n x n matrix.
 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = 0, b = 0;
        int expsum = 0, actualsum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualsum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expsum = n * n * (n * n + 1) / 2;
        b = expsum + a - actualsum;
        ans.push_back(b);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Example 1 -> repeating: " << result1[0]
         << ", missing: " << result1[1] << '\n';

    vector<vector<int>> grid2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Example 2 -> repeating: " << result2[0]
         << ", missing: " << result2[1] << '\n';

    return 0;
}
