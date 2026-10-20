/*
 * File: gas_station.cpp
 * Description: Finds the unique gas-station start index that allows
 *              completing a circular route.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;
        int start = 0;
        int currgas = 0;

        for (int i = 0; i < static_cast<int>(gas.size()); i++) {
            totgas += gas[i];
            totcost += cost[i];
            currgas += gas[i] - cost[i];

            if (currgas < 0) {
                start = i + 1;
                currgas = 0;
            }
        }

        return totgas < totcost ? -1 : start;
    }
};

int main() {
    Solution solution;

    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << solution.canCompleteCircuit(gas1, cost1) << '\n';

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << solution.canCompleteCircuit(gas2, cost2) << '\n';

    return 0;
}
