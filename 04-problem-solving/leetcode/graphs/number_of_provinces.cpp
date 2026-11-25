/*
 * File: number_of_provinces.cpp
 * Description: Counts connected groups of cities using recursive depth-first
 *              search over the adjacency matrix.
 *
 * Time Complexity: O(n^2) - each city scans its row in the adjacency matrix.
 * Space Complexity: O(n) - visited array and recursion stack.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[i] = true;

        for (size_t j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == 1 && !vis[j]) {
                dfs(static_cast<int>(j), adj, vis);
            }
        }
    }

public:
    // Time Complexity: O(n^2)
    // Space Complexity: O(n) for visited cities and recursion stack.
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numofprovinces = 0;
        int n = static_cast<int>(isConnected.size());
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis);
                numofprovinces++;
            }
        }

        return numofprovinces;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Example 1: " << solution.findCircleNum(isConnected1) << '\n';

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Example 2: " << solution.findCircleNum(isConnected2) << '\n';

    return 0;
}
