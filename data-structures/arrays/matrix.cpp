// Time Complexity: O(n^2)

#include<iostream>
#include<utility>
using  namespace std;

pair<int, int> linearsearch(int matrix[][3], int rows, int col, int key){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0; j < col; j++){
            if(matrix[i][j] == key){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
int main(){
    int matrix[3][3];
     
    int rows = 3;
    int col = 3;

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

    matrix[1][1] = 10;
    cout << matrix[1][2] << endl;
    cout << matrix[1][1] << endl;
    pair<int, int> result = linearsearch(matrix, rows, col, 9);
    cout << "(" << result.first << ", " << result.second << ")";
    return 0;
}