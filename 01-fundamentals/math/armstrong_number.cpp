#include<iostream>
using namespace std;

// Time Complexity: O(log n)
bool isarmstrong(int n){
    int copyN = n;
    int sumofcubes = 0;
    while( n != 0){
        int dig = n % 10;
        sumofcubes += (dig*dig*dig);
        n = n/10;
    }
    return sumofcubes == copyN;
}
int main(){
    int n = 153;
    if(isarmstrong(n)){
        cout <<" isarmstrong number" << endl;
    }else {
        cout << "not armstrong number" << endl;
    }
    return 0;
}