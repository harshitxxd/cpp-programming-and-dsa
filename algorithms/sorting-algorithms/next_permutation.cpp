/*
 * File: next_permutation.cpp
 * Description: This program finds the next lexicographic permutation of a sequence.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1 , n = nums.size();
        for (int i = n -2; i >=0 ; i--){
            if (nums[i] < nums[i+1]){
                pivot = i;
                break ;
            }
        }
        
        if (pivot == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }

        for (int i = n -1 ;i > pivot ; i--){
            if (nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        int i = pivot +1 , j = n-1;
        while(i <= j){
            swap(nums[i++],nums[j--]);

        } 
        
    }
    void printvector(vector<int>nums ){
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            cout << nums[i] << " " ;
        }
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,2,3};
    sol.nextPermutation(nums);
    sol.printvector(nums);
    return 0;
}

