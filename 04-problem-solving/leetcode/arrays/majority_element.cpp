/*
 * File: majority_element.cpp
 * Description: This program identifies a majority element using the Boyer-Moore voting algorithm.
 *
 */

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = 0;
        for (int num : nums){
            if (count == 0){
                candidate = num;
            }
            if (num == candidate){
                count ++;
            }
            else {
                count --;
            }  
        }
        count = 0;
        for (int num : nums){
            if (num == candidate){
                count ++;
            }
        }
        if (count > n/2){
            return candidate;
        }
        else {
            return -1;
        }
    }
};
int main(){
    Solution sol ;
    vector<int> nums = {3,2,3};
    int ans = sol.majorityElement(nums);
    cout << "the majority element is "<< ans << endl;
    return 0; 

}