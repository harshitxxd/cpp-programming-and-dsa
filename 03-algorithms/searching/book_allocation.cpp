/*
 * File: book_allocation.cpp
 * Description: This program allocates pages to students while minimizing the highest allocation.
 *
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n log n)
bool isvalid(vector<int> &arr , int n,int m ,int maxallowedpages){
    int stu = 1 , pages = 0;
    for (int i = 0; i < n ; i++){
        if (arr[i] > maxallowedpages){
            return false;
        }
        if (pages + arr[i] <= maxallowedpages){
            pages += arr[i];
        }
        else {
            stu ++;
            pages = arr[i];
        }
        
    }
    return stu > m ? false : true ;
};
int allocatebook(vector<int> &arr,int n , int  m){
    if( m>n){return -1;}

    int sum = 0;

    for(int i =0 ; i < n; i++){
        sum += arr[i];
    }

    int st =0 , end =sum; 
    int ans = -1;
    while(st <= end ){
        int mid = st + (end - st)/2;
        if (isvalid(arr,n,m,mid)){
            ans = mid ;
            end = mid -1;
        }
        else {
            st = mid +1;
        }
    }
    return ans ;
};
int main(){
    vector<int>arr = {2,1,3,4};
    int n = 4 ,m = 2;
    cout << allocatebook(arr,n,m);
    return 0;
}