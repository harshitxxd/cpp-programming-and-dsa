/*
 * File: sort_arrays_0_1_2.cpp
 * Description: This program sorts an array containing only 0s, 1s, and 2s in linear time.
 *
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums,int n) {
        
        int low = 0 , mid = 0, high = n-1;
        while(mid <= high){

            if (nums[mid] == 0){
                swap(nums[low],nums[mid]);
                mid ++ , low++;
            }

            else if (nums[mid]== 1){
                mid ++;
            }

            else{
                swap(nums[high],nums[mid]);
                high --;
            }
        }
    }
    void printvector(vector<int>nums, int n ){
        for (int i = 0 ; i < n; i++){
            cout << nums[i] << " " ;
        }
    }
};

int main(){
    Solution sol;
    vector<int>nums = {2,0,2,1,1,0};
    int n = nums.size();
    sol.sortColors(nums,n);
    sol.printvector(nums,n);
    return 0;

}