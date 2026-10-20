/*
 * File: stack_vector.cpp
 * Description: Implements a LIFO stack using a vector.
 */

#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(1) amortized for push, O(1) for pop, top, empty
// Space Complexity: O(n) - stores n elements in a dynamic vector
class stack{
    vector<int> v;
    
    public :
        void push(int val){
            v.push_back(val);   
        }

        void pop(){
            v.pop_back();
        }

        int top(){
            return v[v.size()-1];
        }

        bool empty(){
            return v.size() == 0;
        }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}