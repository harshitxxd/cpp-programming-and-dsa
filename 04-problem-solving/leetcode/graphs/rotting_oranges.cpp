/*
 * File: rotting_oranges.cpp
 * Description: Finds the minimum time for all reachable fresh oranges to rot
 *              using multi-source breadth-first search.
 *
 * Time Complexity: O(m * n) - each cell is processed at most once.
 * Space Complexity: O(m * n) - the queue can contain cells from the grid.
 *
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) for the queue.
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        if (rows == 0) {
            return 0;
        }
        int columns = static_cast<int>(grid[0].size());

        queue<pair<int, int>> rotten;
        int fresh = 0;

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (grid[row][column] == 2) {
                    rotten.push({row, column});
                } else if (grid[row][column] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        const int rowOffset[] = {-1, 0, 1, 0};
        const int columnOffset[] = {0, 1, 0, -1};

        while (!rotten.empty() && fresh > 0) {
            int levelSize = static_cast<int>(rotten.size());
            bool rottedFreshOrange = false;

            for (int i = 0; i < levelSize; i++) {
                pair<int, int> current = rotten.front();
                rotten.pop();

                for (int direction = 0; direction < 4; direction++) {
                    int nextRow = current.first + rowOffset[direction];
                    int nextColumn = current.second + columnOffset[direction];

                    if (nextRow >= 0 && nextRow < rows &&
                        nextColumn >= 0 && nextColumn < columns &&
                        grid[nextRow][nextColumn] == 1) {
                        grid[nextRow][nextColumn] = 2;
                        fresh--;
                        rottedFreshOrange = true;
                        rotten.push({nextRow, nextColumn});
                    }
                }
            }

            if (rottedFreshOrange) {
                minutes++;
            }
        }

        return fresh == 0 ? minutes : -1;
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
