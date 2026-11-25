/*
 * File: number_of_provinces.cpp
 * Description: Counts connected groups of cities using recursive depth-first
 *              search or disjoint set union over the adjacency matrix.
 *
 * Time Complexity: O(n^2) - each city scans its row in the adjacency matrix.
 * Space Complexity: O(n) - visited array and recursion stack.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int findDSU(int city, vector<int>& parent) {
        if (parent[city] == city) {
            return city;
        }
        parent[city] = findDSU(parent[city], parent);
        return parent[city];
    }

    void unionCities(int first, int second, vector<int>& parent,
                     vector<int>& rank) {
        int firstParent = findDSU(first, parent);
        int secondParent = findDSU(second, parent);

        if (firstParent == secondParent) {
            return;
        }

        if (rank[firstParent] > rank[secondParent]) {
            parent[secondParent] = firstParent;
        } else if (rank[firstParent] < rank[secondParent]) {
            parent[firstParent] = secondParent;
        } else {
            parent[secondParent] = firstParent;
            rank[firstParent]++;
        }
    }

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

    // Time Complexity: O(n^2) with nearly constant union/find operations.
    // Space Complexity: O(n) for parent and rank arrays.
    int findCircleNumUsingDSU(vector<vector<int>>& isConnected) {
        int n = static_cast<int>(isConnected.size());
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int city = 0; city < n; city++) {
            parent[city] = city;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionCities(i, j, parent, rank);
                }
            }
        }

        int provinces = 0;
        for (int city = 0; city < n; city++) {
            if (findDSU(city, parent) == city) {
                provinces++;
            }
        }
        return provinces;
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
    cout << "Example 1 DSU: "
         << solution.findCircleNumUsingDSU(isConnected1) << '\n';

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Example 2: " << solution.findCircleNum(isConnected2) << '\n';
    cout << "Example 2 DSU: "
         << solution.findCircleNumUsingDSU(isConnected2) << '\n';

    return 0;
}
