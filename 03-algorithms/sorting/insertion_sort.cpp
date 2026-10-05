/*
 * File: insertion_sort.cpp
 * Description: This program sorts an array in ascending order using the insertion sort algorithm.
 *
 */

#include<iostream>
using namespace std;

// Time Complexity: O(n^2)
void insertion_sort(int arr[], int n){

    for (int i = 1 ; i < n; i++){
        int current = arr[i];
        int previous = i-1;

        while (previous >= 0 && arr[previous] > current){
            arr[previous +1] = arr[previous];
            previous -- ;
        }
        arr[previous+1]= current;
    }
}
void printarr(int arr[],int n){
    for (int i = 0 ; i < n;i++){
        cout << arr[i] << " " ; 
    }
    
}
int main(){
    
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);
    printarr(arr,n);
    return 0;
}