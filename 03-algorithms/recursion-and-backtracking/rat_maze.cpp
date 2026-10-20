/*
 * File: rat_maze.cpp
 * Description: Finds paths through a maze by recursively exploring valid
 *              neighboring cells.
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(4^(n^2)) - in the worst case, 4 recursive branches per cell.
// Space Complexity: O(n^2) - for the recursion call stack and paths in an n x n grid.
void helper (vector<vector<int>> &mat,int r,int c,string path , vector<string>&ans){
    int n = mat.size();
    if(r < 0 || c < 0 || r >= n|| c >= n || mat[r][c] == 0 || mat[r][c] == -1){
        return ;
    }

    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return ; 
    }
 
    mat[r][c] = -1; 

    helper(mat,r+1,c,path+"d",ans);
    helper(mat,r-1,c,path+"u",ans);
    helper(mat,r,c-1,path+"l",ans);
    helper(mat,r,c+1,path+"r",ans);

    mat[r][c] = 1;
}
vector<string> findpath(vector<vector<int>> &mat){
    int n = mat.size();
   
    vector<string> ans;
    string path = "";
    helper(mat ,0,0,path,ans);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findpath(mat);
    for(string path:ans){
        cout << path << endl;
    }

    return 0;
}