/*
 * File: search_in_rotated_sorted_array.cpp
 * Description: This program searches for an element in a rotated sorted array.
 *
 */

#include<iostream>
#include<vector>
using namespace std;
class solution{
    public :
    int search(vector<int>& nums , int target){
        int st = 0 ;
        int end = nums.size()-1 ;
        while (st <= end ){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                return mid;
            }           
            else if(nums[st] <= nums[mid]){
                if (nums[st] <= target && target <= nums[mid]){
                    end = mid-1;
                }
                else {
                    st = mid + 1;
                }
            }
            else {
                if (nums[mid] <= target  && target <= nums[end]){
                        st = mid +1 ;
                }
                else {
                    end = mid - 1 ;
                }
            }


        }
        return -1;
    }
};
int main(){
    solution sol;
    vector<int>nums = {4,5,6,7,0,1,2}; 
    int target = 0;
    cout << sol.search(nums,target);
    return 0;
    
}