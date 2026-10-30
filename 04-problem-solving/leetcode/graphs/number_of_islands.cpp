/*
 * File: number_of_islands.cpp
 * Description: Counts the connected components of land in a 2D grid using
 *              recursive depth-first search.
 *
 * Time Complexity: O(m * n) - each cell is visited at most once.
 * Space Complexity: O(m * n) - visited cells and the recursive call stack.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void dfs(int i, int j, vector<vector<bool>>& visited,
             vector<vector<char>>& grid, int rows, int columns) {
        if (i < 0 || j < 0 || i >= rows || j >= columns ||
            visited[i][j] || grid[i][j] != '1') {
            return;
        }

        visited[i][j] = true;

        dfs(i - 1, j, visited, grid, rows, columns);
        dfs(i, j + 1, visited, grid, rows, columns);
        dfs(i + 1, j, visited, grid, rows, columns);
        dfs(i, j - 1, visited, grid, rows, columns);
    }

public:
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) for visited cells and recursion stack.
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid, rows, columns);
                    islands++;
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
    cout << "Example 1: " << solution.numIslands(grid1) << '\n';

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Example 2: " << solution.numIslands(grid2) << '\n';

    return 0;
}
