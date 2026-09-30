#include<iostream>
#include<list>
using namespace std;

// Time Complexity: O(n)
int main(){
    list<int> l;
    
    l.push_back(1);
    l.push_front(2);
    l.emplace_back(3);
    l.pop_back();
    l.pop_front();

    for (int val : l){
        cout << val << endl;
    }
    return 0;
}