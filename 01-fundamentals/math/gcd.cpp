#include<iostream>
using namespace std;

// Time Complexity: O(log n)
int gcd(int a,int b){
    while ( a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a ;
        }
    }
    if ( a == 0 ) return b;
    return a ;
}

int gcdrec(int a , int b){
    if(b == 0) return a;
    return gcdrec(b, a % b);
}

int lcm (int a ,int b){
    return (a*b) / gcdrec(a,b);
}
int main(){
    cout << gcd(20,28) << endl;
    cout << gcdrec(20,28) << endl;
    cout << lcm(20,28) << endl; 
    return 0;
}