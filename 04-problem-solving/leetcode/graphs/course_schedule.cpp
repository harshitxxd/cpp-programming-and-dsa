/*
 * File: course_schedule.cpp
 * Description: Determines whether all courses can be completed by detecting
 *              cycles in the prerequisite graph using recursive DFS.
 *
 * Time Complexity: O(V * E) - each visited course scans all E prerequisites.
 * Space Complexity: O(V) - visited arrays and the recursion stack.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool iscycledfs(int src, vector<bool>& vis, vector<bool>& recpath,
                    vector<vector<int>>& prerequisites) {
        vis[src] = true;
        recpath[src] = true;

        for (int i = 0; i < static_cast<int>(prerequisites.size()); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];

            if (prerequisite == src) {
                if (!vis[course]) {
                    if (iscycledfs(course, vis, recpath, prerequisites)) {
                        return true;
                    }
                } else if (recpath[course]) {
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false;
    }

public:
    // Time Complexity: O(V * E)
    // Space Complexity: O(V) for visitation state and recursion stack.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        for (int course = 0; course < numCourses; course++) {
            if (!vis[course] &&
                iscycledfs(course, vis, recpath, prerequisites)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Example 1: "
         << (solution.canFinish(2, prerequisites1) ? "true" : "false") << '\n';

    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Example 2: "
         << (solution.canFinish(2, prerequisites2) ? "true" : "false") << '\n';

    return 0;
}
