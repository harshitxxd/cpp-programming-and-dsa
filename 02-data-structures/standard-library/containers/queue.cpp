#include<iostream>
#include<queue>
using namespace std;

// Time Complexity: O(n)
int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    

    while(!q.empty()){
        cout << q.front() << " " ;
        q.pop();
    }

    cout << endl;

    
    priority_queue<int> q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);

    while(!q1.empty()){
        cout << q1.top() << " " ;
        q1.pop();
    }
    
    cout << endl;

    priority_queue<int,vector<int>,greater<int>> q2;

    
    q2.push(10);
    q2.push(20);
    q2.push(30);

    while(!q2.empty()){
        cout << q2.top() << " " ;
        q2.pop();
    }

    return 0;

}