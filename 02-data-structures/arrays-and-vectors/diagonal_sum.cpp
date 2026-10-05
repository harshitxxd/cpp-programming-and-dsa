#include <iostream>
using namespace std;

// Time Complexity: O(n^2)
int diagonal_sum(int matrix[][4], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum = matrix[i][i];
      if(i != n-1-i){
        sum += matrix[i][n-i-1];
      }
    }
    return sum;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4;

    cout << diagonal_sum(matrix, n) << endl;
    return 0;
}