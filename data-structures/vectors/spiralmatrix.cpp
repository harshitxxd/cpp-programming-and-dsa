#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n * m)
class solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& mat){
        int m = mat.size(), n = mat[0].size();
        int srow = 0,scol = 0, erow = m-1, ecol = n-1;
        vector<int> ans ;
    
    while(scol <= ecol && srow <= erow){
        for(int j = scol; j <= ecol;j++){
            ans.push_back(mat[srow][j]);
        }

        for(int i = srow+1; i <= erow ; i++){
            ans.push_back(mat[i][ecol]);
        }
        for(int j = ecol-1;j >= scol;j--){
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][j]);
        }
        for(int i = erow-1; i >= srow+1;i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(mat[i][scol]);
        }
        srow ++ ; erow -- ; scol ++, ecol --;
    }
    return ans ;
    }

    void print(vector<vector<int>> mat ){
        for ( int value : spiralOrder(mat)){
            cout << value << " ";
        }
        cout << endl;
    }
};

int main(){
    solution sol ;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat1 =  {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    sol.print(mat);
    sol.print(mat1);
    return 0;
}