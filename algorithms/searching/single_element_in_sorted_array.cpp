/*
 * File: single_element_in_sorted_array.cpp
 * Description: This program finds the single element that occurs once while all others appear twice.
 *
 */

#include<iostream>
#include<vector>
using namespace std;
class solution {
    public:
    int singleelement(vector<int>& nums){
        int st = 0;
        int n = nums.size();
        int end =  n- 1;
        if (n == 1) return nums[0];
        while ( st <= end ){
            int mid = st + (end - st )/2;
            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if (mid == n-1 && nums[n-1] == nums[n-2]) return nums[mid];
            if (nums[mid] != nums [mid+1] && nums[mid] != nums[mid-1]) return nums[mid];
            if (mid % 2 == 0){
                if (nums[mid] == nums [mid -1]){
                    end = mid -1;
                }
                else {
                    st = mid +1;
                }
            }
            else {
                if (nums[mid] == nums[mid-1]){
                    st = mid +1;
                }
                else {
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};
int main(){
    solution sol;
    vector<int>nums = {1,1,2,3,3,4,4,8,8};
    vector<int>nums2 = {3,3,7,7,10,11,11};
    cout << sol.singleelement(nums) << endl;
    cout << sol.singleelement(nums2) << endl;
    return 0;
}