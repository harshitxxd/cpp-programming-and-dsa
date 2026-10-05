/*
 * File: two_pointer_pairsum.cpp
 * Description: This program finds pairs in a vector whose sum matches a target value using the two-pointer technique.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)


vector<int> pairsum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;

    vector<int> ans = pairsum(nums, target);
    cout << ans[0] << ',' << ans[1] << endl;
    return 0;
}
