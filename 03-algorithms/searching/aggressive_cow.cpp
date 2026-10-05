/*
 * File: aggressive_cow.cpp
 * Description: This program solves the aggressive cows problem by checking the maximum valid minimum distance.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity: O(n log n)
bool ispossible(vector<int>& arr,int n,int c, int maxalloweddist){
    int cows = 1 , laststallpos = arr[0];

    for(int i =0 ; i < n; i++){

        if (arr[i] - laststallpos >= maxalloweddist){
            cows ++;
            laststallpos = arr[i];
        }
        if (cows == c){
            return true;
        }

    }

    return false;
}

int getdistance(vector<int>& arr, int n, int c){
    sort(arr.begin(),arr.end());

    int st =1 , end = arr[n-1]-arr[0],ans = -1;
    while (st <= end ){
        int mid = st + (end - st)/2;
    
        if(ispossible(arr,n,c,mid)){
            ans = mid ;
            st = mid +1;
        }
        else{
            end = mid -1;
        } 
    }
    return ans ;

}

int main(){
    vector<int>arr = {1,2,8,4,9};
    int c = 3, n = 5;
    
    cout << getdistance(arr,n,c) << endl;
    return 0 ;
    

}