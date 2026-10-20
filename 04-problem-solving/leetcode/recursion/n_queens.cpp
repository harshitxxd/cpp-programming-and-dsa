/*
 * File: n_queens.cpp
 * Description: Solves the N-Queens problem by placing queens without
 *              attacking one another.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool issafe(vector<string>& board, int row, int col, int n) {
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nqueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (issafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    // Time complexity: O(n * n! + S * n^2), where S is the number of solutions.
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nqueens(board, 0, n, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    for (int n : {4, 1}) {
        vector<vector<string>> solutions = sol.solveNQueens(n);
        cout << "n = " << n << ", solutions = " << solutions.size() << '\n';
        for (const vector<string>& board : solutions) {
            for (const string& row : board) {
                cout << row << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}
