#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n log n) - divide-and-conquer like merge sort.
// Space Complexity: O(n) - temporary vector used during merging.
int merge(vector<int>&arr, int st, int mid , int end){
    vector<int> temp ;
    int i = st , j = mid +1;
    int invcount = 0 ;

    while(i <= mid && j <= end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invcount += (mid-i+1);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<= end){
        temp.push_back(arr[j]);
        j++; 
    }

    for(int idx =0 ; idx < temp.size() ; idx++){
        arr[idx+st] = temp[idx];
    }
    return invcount ;
}

int mergesort(vector<int>&arr, int st , int end ){
    if(st < end){
        int mid = st + (end - st)/2;
        int leftcount = mergesort(arr,st,mid);
        int rightcount = mergesort(arr,mid+1,end);

        int invcount = merge (arr,st ,mid ,end);
        return leftcount + rightcount + invcount;
    }
    return 0;
}

int main(){
    vector<int>arr = {6,3,5,2,7};
    vector<int>arr1 = {1, 3, 5, 10, 2, 6, 8, 9};
    int ans = mergesort(arr1,0,arr1.size()-1);
    cout << "inv count : "<< ans << endl;
    return 0;
}