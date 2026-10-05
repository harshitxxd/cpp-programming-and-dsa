#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int r, int c, int n, int expval) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expval) {
            return false;
        }

        if (expval == n * n - 1) {
            return true;
        }
        int ans1 = isvalid(grid, r - 2, c + 1, n, expval + 1);
        int ans2 = isvalid(grid, r - 1, c + 2, n, expval + 1);
        int ans3 = isvalid(grid, r + 1, c + 2, n, expval + 1);
        int ans4 = isvalid(grid, r + 2, c + 1, n, expval + 1);
        int ans5 = isvalid(grid, r + 2, c - 1, n, expval + 1);
        int ans6 = isvalid(grid, r + 1, c - 2, n, expval + 1);
        int ans7 = isvalid(grid, r - 1, c - 2, n, expval + 1);
        int ans8 = isvalid(grid, r - 2, c - 1, n, expval + 1);
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    // Time complexity: O(n^2), since at most 8 moves are checked per visited cell.
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid, 0, 0, static_cast<int>(grid.size()), 0);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22},
    };
    cout << "Example 1 -> "
         << (sol.checkValidGrid(grid1) ? "true" : "false") << '\n';

    vector<vector<int>> grid2 = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 7, 4},
    };
    cout << "Example 2 -> "
         << (sol.checkValidGrid(grid2) ? "true" : "false") << '\n';

    return 0;
}
