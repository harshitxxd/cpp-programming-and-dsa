/*
 * File: course_schedule2.cpp
 * Description: Finds a valid ordering of courses to finish all courses using
 *              cycle detection and DFS-based topological sorting.
 *
 * Time Complexity: O(V * E) - each visited course scans all E prerequisites.
 * Space Complexity: O(V) - visited arrays, recursion call stack, and topological stack.
 *
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool iscycle(int src, vector<bool>& vis, vector<bool>& recpath, vector<vector<int>>& edges) {
        vis[src] = true;
        recpath[src] = true;

        for (size_t i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (src == u) {
                if (!vis[v]) {
                    if (iscycle(v, vis, recpath, edges)) {
                        return true;
                    }
                } else if (recpath[v]) {
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }

    void topological(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& edges) {
        vis[src] = true;
        for (size_t i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];
            if (src == u) {
                if (!vis[v]) {
                    topological(v, vis, s, edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (iscycle(i, vis, recpath, edges)) {
                    return ans;
                }
            }
        }

        stack<int> s;
        vis.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topological(i, vis, s, edges);
            }
        }
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

void printVector(const vector<int>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << values[i];
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    // Example 1: numCourses = 2, prerequisites = [[1, 0]]
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Example 1: ";
    printVector(solution.findOrder(2, prerequisites1));

    // Example 2: numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Example 2: ";
    printVector(solution.findOrder(4, prerequisites2));

    // Example 3: numCourses = 1, prerequisites = []
    vector<vector<int>> prerequisites3 = {};
    cout << "Example 3: ";
    printVector(solution.findOrder(1, prerequisites3));

    return 0;
}
