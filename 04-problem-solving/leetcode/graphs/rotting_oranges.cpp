/*
 * File: rotting_oranges.cpp
 * Description: Finds the minimum time for all fresh oranges to rot using
 *              multi-source breadth-first search.
 *
 * Time Complexity: O(m * n) - each cell is processed at most once.
 * Space Complexity: O(m * n) - visited cells and the BFS queue.
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) for the visited matrix and queue.
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int columns = static_cast<int>(grid[0].size());
        int minutes = 0;

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        queue<pair<pair<int, int>, int>> oranges;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 2) {
                    oranges.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        while (!oranges.empty()) {
            int i = oranges.front().first.first;
            int j = oranges.front().first.second;
            int time = oranges.front().second;
            oranges.pop();

            minutes = max(minutes, time);

            if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                oranges.push({{i - 1, j}, time + 1});
                visited[i - 1][j] = true;
            }

            if (j + 1 < columns && !visited[i][j + 1] &&
                grid[i][j + 1] == 1) {
                oranges.push({{i, j + 1}, time + 1});
                visited[i][j + 1] = true;
            }

            if (i + 1 < rows && !visited[i + 1][j] &&
                grid[i + 1][j] == 1) {
                oranges.push({{i + 1, j}, time + 1});
                visited[i + 1][j] = true;
            }

            if (j - 1 >= 0 && !visited[i][j - 1] &&
                grid[i][j - 1] == 1) {
                oranges.push({{i, j - 1}, time + 1});
                visited[i][j - 1] = true;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << "Example 1: " << solution.orangesRotting(grid1) << '\n';

    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    cout << "Example 2: " << solution.orangesRotting(grid2) << '\n';

    vector<vector<int>> grid3 = {{0, 2}};
    cout << "Example 3: " << solution.orangesRotting(grid3) << '\n';

    return 0;
}