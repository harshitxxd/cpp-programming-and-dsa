#include<iostream>
#include<set>
using namespace std;

// Time Complexity: O(n)
int main(){
    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    for(int val : s){
        cout << val <<" ";
    }

    cout << endl;

    cout << *s.lower_bound(20) << endl;
    cout << *s.upper_bound(20) << endl;
    return 0;
} 