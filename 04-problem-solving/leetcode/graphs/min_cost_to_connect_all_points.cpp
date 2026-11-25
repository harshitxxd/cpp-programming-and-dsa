/*
 * File: min_cost_to_connect_all_points.cpp
 * Description: Finds the minimum cost to connect all points using Prim's
 *              minimum spanning tree algorithm.
 *
 * Time Complexity: O(n^2 log n) - up to O(n^2) candidate edges are pushed
 *                  into the priority queue.
 * Space Complexity: O(n^2) - the priority queue can hold O(n^2) candidates.
 *
 */

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int mandist(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    // Time Complexity: O(n^2 log n)
    // Space Complexity: O(n^2) for the priority queue.
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = static_cast<int>(points.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        vector<bool> mstset(n, false);
        int mstcost = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();

            if (mstset[node]) {
                continue;
            }

            mstset[node] = true;
            mstcost += wt;

            for (int i = 0; i < n; i++) {
                if (!mstset[i]) {
                    int edgewt = mandist(points, node, i);
                    pq.push({edgewt, i});
                }
            }
        }
        return mstcost;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> points1 = {
        {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
    };
    cout << "Example 1: " << solution.minCostConnectPoints(points1) << '\n';

    vector<vector<int>> points2 = {
        {3, 12}, {-2, 5}, {-4, 1}
    };
    cout << "Example 2: " << solution.minCostConnectPoints(points2) << '\n';

    return 0;
}
