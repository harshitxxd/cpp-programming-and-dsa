#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Time Complexity: O(n^2)
bool comparator(pair<int,int>p1,pair<int,int>p2){
    if(p1.second > p2.second) return false;
    if(p1.second < p2.second) return true;

    if(p1.first < p2.first) return true;
    else return false ;
}

int main(){
    int arr[] = {1,3,2,4,7,5,6,8};
    int n = sizeof(arr)/sizeof(int);
    sort (arr,arr + n);

    for(int i = 0;  i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    sort(arr,arr+n,greater<int>());

    for(int i = 0;  i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    vector<pair<int,int>> vec = {{3,1},{2,1},{7,1},{5,2}};

    sort(vec.begin(),vec.end());

    for(auto p : vec){
        cout << p.first << " " << p.second << endl;
    }
    
    cout << endl;

    sort(vec.begin(),vec.end(),comparator);

    for(auto p : vec){
        cout << p.first << " " << p.second << endl;
    }
    

    return 0;
}