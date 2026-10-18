#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(log n)
class solution{
    public: 
    bool searchinrow(vector<vector<int>>& matrix,int target , int row){
        int n = matrix[0].size();
        int st = 0 , end = n-1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(target == matrix[row][mid]){
                return true;
            }
            else if( target > matrix[row][mid]){
                st = mid +1;
            }
            else {
                end = mid -1;
            }
        }
        return false;
    }
    bool searchmatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size(),n = matrix[0].size();

        int startrow = 0, endrow = m -1;
        while(startrow <= endrow){
            int midrow = startrow + (endrow - startrow)/2;

            if(target >= matrix[midrow][0] && target <= matrix[midrow][n-1]){
                return searchinrow(matrix,target,midrow);
            }
            else if(target >= matrix[midrow][n-1]){
                startrow = midrow +1;
            }
            else {
                endrow = midrow-1;
            }

        }
        return false;
    }
};

int  main (){
    solution sol;
    vector<vector<int>> matrix = {{1,3,5,7,},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << sol.searchmatrix(matrix,target);
    return 0 ;
}