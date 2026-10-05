/*
 * File: selection_sort.cpp
 * Description: This program sorts an array in ascending order using the selection sort algorithm.
 *
 */

#include<iostream>
using namespace std;

// Time Complexity: O(n^2)
void selectionsort(int arr[], int n ){
    for(int i = 0 ; i < n; i++){
        int smallest = i;

        for (int j = i+1; j < n; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }

        swap(arr[i],arr[smallest]);
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
    selectionsort(arr,n);
    printarr(arr,n);
    return 0;
}