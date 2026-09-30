/*
 * File: peak_index_in_mountain_array.cpp
 * Description: This program finds the peak index in a mountain array.
 *
 */

#include<iostream>
#include<vector>
using namespace std;
class solution {
    public :
    int peakindex(vector<int>& arr){
        int st = 1;
        int end = arr.size() - 2;
        while (st <= end){
            int mid = st +(end -st)/2;
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid +1 ]){
                return mid ;
            }
            else if ( arr[mid -1] < arr[mid]){
                st =  mid +1;
            }
            else {
                end = mid -1;
            }
        }
        return -1;
    }
};
int main(){
    solution sol ;
    vector<int>arr = {0,1,0};
    vector<int>arr1 = {0,2,1,0};
    vector<int>arr2 = {0,10,5,2};
    vector<int>arr3 = {3,4,5,1};
    cout << sol.peakindex(arr) << endl;
    cout << sol.peakindex(arr1) << endl ;
    cout << sol.peakindex(arr2) << endl ;
    cout << sol.peakindex(arr3) << endl ;
    return 0;
}