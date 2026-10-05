/*
 * File: merge_2_sorted_array.cpp
 * Description: This program merges two sorted arrays into a single sorted array.
 *
 */

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0){

            if (nums1[i] >= nums2[j]){
                nums1[idx --] = nums1[i--];
            }

            else{
                nums1[idx--] = nums2[j--];
            }
        }

        while (j >= 0 ){
            nums1[idx--] = nums2[j--];
        }
        
    }

    void printvector(vector<int>nums1,int n,int m ){
        int idx = m + n;
        for (int i = 0 ; i < idx; i++){
            cout << nums1[i] << " " ;
        }
    }
};

int main(){
    Solution sol;
    vector<int>nums1 = {1,2,3,0,0,0};
    int m =3;
    vector<int>nums2 ={2,5,6};
    int n = 3;
    sol.merge(nums1,m,nums2,n);
    sol.printvector(nums1,n,m);
    return 0;
    
}