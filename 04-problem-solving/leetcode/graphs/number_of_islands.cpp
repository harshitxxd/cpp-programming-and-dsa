/*
 * File: number_of_islands.cpp
 * Description: Counts the connected components of land in a 2D grid.
 *
 * Time Complexity: O(m * n) - each cell is visited at most once.
 * Space Complexity: O(m * n) - visited cells and the iterative DFS stack.
 *
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        int islands = 0;
        const int rowOffsets[] = {-1, 0, 1, 0};
        const int columnOffsets[] = {0, 1, 0, -1};

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (grid[row][column] != '1' || visited[row][column]) {
                    continue;
                }

                islands++;
                vector<pair<int, int>> stack = {{row, column}};
                visited[row][column] = true;

                while (!stack.empty()) {
                    pair<int, int> cell = stack.back();
                    stack.pop_back();

                    for (int direction = 0; direction < 4; direction++) {
                        int nextRow = cell.first + rowOffsets[direction];
                        int nextColumn = cell.second + columnOffsets[direction];

                        if (nextRow >= 0 && nextRow < rows &&
                            nextColumn >= 0 && nextColumn < columns &&
                            grid[nextRow][nextColumn] == '1' &&
                            !visited[nextRow][nextColumn]) {
                            visited[nextRow][nextColumn] = true;
                            stack.push_back({nextRow, nextColumn});
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Example 1: " << solution.numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Example 2: " << solution.numIslands(grid2) << endl;

    return 0;
}
