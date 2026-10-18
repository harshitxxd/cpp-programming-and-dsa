#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Time Complexity: O(n) - each element is pushed and popped at most once.
// Space Complexity: O(n) - monotonic stack and result vector.
int main(){
    vector<int>arr = {3, 1, 0, 8, 6};
    stack<int>s;
    vector<int>ans(arr.size(),0);
    for(int i = 0; i < arr.size()  ; i++){
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }

        if(s.empty()){
                ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for (int val : ans){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}