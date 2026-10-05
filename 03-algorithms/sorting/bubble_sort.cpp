/*
 * File: bubble_sort.cpp
 * Description: This program sorts an array in ascending order using the bubble sort algorithm.
 *
 */

#include<iostream>
using namespace std;

// Time Complexity: O(n^2)
void bubblesort(int arr[],int n){

    for(int i = 0; i < n-1;i++){
        bool isswap = false;

        for(int j =0 ; j < n -i-1;j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap = true;
            }
        }

        if(! isswap){
            return;
        }
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
    bubblesort(arr,n);
    printarr(arr,n);
    return 0;
}