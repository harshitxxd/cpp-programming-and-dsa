#include<iostream>
using namespace std;

// Time Complexity: O(n) for printnums, factorial, and sum functions
// Space Complexity: O(n) - recursion call stack depth
void printnums(int n){
    if(n == 1){
        cout << "1\n";
        return ;
    }
    cout << n << " " ;
    printnums(n-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n* factorial(n-1);
}

int sum(int n){
    if( n == 1){
        return 1;
    }
    return  n + sum(n-1);
}

int main(){
    printnums(10);
    cout << factorial(4) << endl;
    cout << sum(4) << endl;
    return 0;
}