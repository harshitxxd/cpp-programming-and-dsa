/*
 * File: flood_fill.cpp
 * Description: Recolors the four-directionally connected region containing
 *              the starting pixel using recursive depth-first search.
 *
 * Time Complexity: O(m * n) - each pixel in the connected region is visited once.
 * Space Complexity: O(m * n) - recursion stack in the worst case.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) for the recursion stack.
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,
             int orgcolor) {
        int rows = static_cast<int>(image.size());
        int columns = static_cast<int>(image[0].size());
        if (i < 0 || j < 0 || i >= rows || j >= columns ||
            image[i][j] == newcolor || image[i][j] != orgcolor) {
            return;
        }

        image[i][j] = newcolor;

        dfs(image, i - 1, j, newcolor, orgcolor);
        dfs(image, i, j + 1, newcolor, orgcolor);
        dfs(image, i + 1, j, newcolor, orgcolor);
        dfs(image, i, j - 1, newcolor, orgcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

void printImage(const vector<vector<int>>& image) {
    cout << '[';
    for (size_t i = 0; i < image.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << '[';
        for (size_t j = 0; j < image[i].size(); j++) {
            if (j > 0) {
                cout << ", ";
            }
            cout << image[i][j];
        }
        cout << ']';
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<vector<int>> image1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    cout << "Example 1: ";
    printImage(solution.floodFill(image1, 1, 1, 2));

    vector<vector<int>> image2 = {
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Example 2: ";
    printImage(solution.floodFill(image2, 0, 0, 0));

    return 0;
}
