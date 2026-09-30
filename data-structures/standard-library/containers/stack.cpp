#include<iostream>
#include<stack>
using namespace std;

// Time Complexity: O(n)
int main(){
    stack<int> s;
    stack<int> s1;
    stack<int> s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.swap(s1);

    cout << s1.size() << endl;
    cout << s2.size() << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;

    cout << endl;

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}