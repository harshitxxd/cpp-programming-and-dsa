/*
 * File: maximum_subarray_sum.cpp
 * Description: This program finds the maximum sum of any contiguous subarray using Kadane's algorithm.
 *
 */

#include <iostream>
#include<vector>
#include <climits>
using namespace std;

class solution {
    public :
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        int maxsum = INT_MIN;
        int cursum = 0;

        for (int i = 0; i < n; i++) {
            cursum += nums[i];
            maxsum = max(maxsum, cursum);
            if (cursum < 0) {
                cursum = 0;
            }
        }
        return maxsum;

    }
};

int main() {
    solution sol;
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums)<< endl;
    return 0;
}
