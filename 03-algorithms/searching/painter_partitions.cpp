/*
 * File: painter_partitions.cpp
 * Description: This program divides work among painters while minimizing the maximum time spent.
 *
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Time Complexity: O(n log n)
bool ispossible(vector<int>arr,int n, int m, int maxallowdtime){

    int painter = 1 , time = 0;

    for (int i = 0 ; i < n; i++){

        if(arr[i] > maxallowdtime){
            return false;
        }

        if (time + arr[i] <= maxallowdtime){
            time += arr[i];
        }

        else {
            painter ++;
            time  = arr[i];
        }
    }

    return painter > m ? false : true ;
}

int mintimetopaint(vector<int>&arr ,int n , int m){

    if (m > n){return  -1 ;}

    int sum = 0 , maxval = INT_MIN;

    for(int i = 0; i < n ; i++){
        sum += arr[i];
        maxval = max(maxval,arr[i]);
    }

    int st = maxval , end = sum , ans = -1;

    while(st <= end ){

        int mid = st +(end-st)/2;

        if (ispossible(arr,n,m,mid)){
            ans = mid ;
            end = mid -1;
        }

        else{
            st = mid +1;
        }

    }

    return ans ;
}
int main(){

    vector<int>arr = {40,30,10,20};
    int n = 4 , m = 2;
    cout <<mintimetopaint(arr,n,m) << endl;
    return 0;

    return 0;
}