/*
 * File: merge_sort.cpp
 * Description: Sorts an integer array using the merge sort algorithm.
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n log n) - divides array log n times and merges each level in O(n).
// Space Complexity: O(n) - temporary storage used during merge step plus O(log n) call stack.
void merge(vector<int>&arr, int st , int mid, int end){
    vector<int>temp;
    int i = st , j = mid+1;
    while (i <= mid && j <=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0;idx < temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
}
void mergesort(vector<int>&arr,int st , int end){
    if(st < end){
        int mid = st + (end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}
int main(){
    vector<int> arr = {12,31,35,8,32,17};
    mergesort(arr,0,arr.size()-1);
    for (int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}