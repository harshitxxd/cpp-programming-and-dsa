/*
 * File: find_missing_and_repeated_values_frequency.cpp
 * Description: Finds repeated and missing matrix values using frequency counting.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        vector<int> count(N + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        int repeating = -1;
        int missing = -1;
        for (int i = 1; i <= N; i++) {
            if (count[i] == 2) {
                repeating = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }

        return {repeating, missing};
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
