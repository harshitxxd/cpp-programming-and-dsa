// Time Complexity: O(n^2)

#include<iostream>
using  namespace std;

int maximum_row_sum(int matrix[3][3],int row ,int col){
    int maxrowsum = INT_MIN;
    for(int i = 0;i < row;i++){
        int rowsum = 0;
        for(int j = 0; j < col;j++){
            rowsum += matrix[i][j];
        }
        maxrowsum = max(maxrowsum,rowsum);
    } 
    return maxrowsum;
}

int maximum_col_sum(int matrix[3][3],int row ,int col){
    int maxcolsum = INT_MIN;
    for(int i = 0;i < row;i++){
        int colsum = 0;
        for(int j = 0; j < col;j++){
            colsum += matrix[j][i];
        }
        maxcolsum = max(maxcolsum,colsum);
    } 
    return maxcolsum;
}

int main(){
    int matrix[3][3];
     
    int rows = 3;
    int col = 3;
    cout << "enter the value";
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0; j < col; j++){
            cin >>  matrix[i][j];
        }
        cout << endl;
    }

    for (int i = 0 ; i < rows ; i++){
        for (int j = 0; j < col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << maximum_row_sum(matrix,rows,col) << endl;
    cout << maximum_col_sum(matrix,rows,col) << endl;;
    return 0;
}