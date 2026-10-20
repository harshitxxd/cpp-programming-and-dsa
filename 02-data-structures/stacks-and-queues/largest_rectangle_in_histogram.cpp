/*
 * File: largest_rectangle_in_histogram.cpp
 * Description: Finds the largest rectangular area that can be formed in a
 *              histogram.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // Time complexity: O(n), as each index is pushed and popped at most once.
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currarea = heights[i] * width;
            ans = max(currarea, ans);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Example 1 -> " << sol.largestRectangleArea(heights1) << '\n';

    vector<int> heights2 = {2, 4};
    cout << "Example 2 -> " << sol.largestRectangleArea(heights2) << '\n';

    return 0;
}
