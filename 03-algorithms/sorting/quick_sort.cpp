/*
 * File: quick_sort.cpp
 * Description: Sorts an integer array using the quicksort partitioning
 *              algorithm.
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n log n) average, O(n^2) worst case (unbalanced partitions).
// Space Complexity: O(log n) average recursive stack space, O(n) worst case.
int partition(vector<int>&arr , int  st , int end ){
    int idx = st -1, pivot = arr[end];
    for ( int j = st ; j < end ; j++){
        if(arr[j] <= pivot){
            idx ++;
            swap(arr[j],arr[idx]);
        }   
    }
     idx ++;
    swap(arr[end],arr[idx]);
    return idx ;
}
void quicksort(vector<int>&arr , int st , int end ){
    if(st < end){
        int pivtidx = partition(arr, st,end) ;

        quicksort(arr,st,pivtidx-1);
        quicksort(arr,pivtidx+1,end);
    }
}
int main(){
    vector<int> arr = {12,31,35,8,32,17};
    quicksort(arr,0,arr.size()-1);
    for(int val : arr){
        cout <<val << " ";
    }
    cout << endl; 
    return 0;

}