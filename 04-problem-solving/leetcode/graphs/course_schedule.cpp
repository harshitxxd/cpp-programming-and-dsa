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
public:
    bool iscycledfs(int src , vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>& edges){
        vis[src] = true;
        recpath[src] = true ;

        for(int i= 0 ;  i< edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src ){
                if(!vis[v]){
                    if(iscycledfs(v,vis,recpath,edges)){
                        return true;
                    }
                }else if(recpath[v]){
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false ;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recpath(n,false);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(iscycledfs(i,vis,recpath ,edges)){
                    return false;
                }
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
