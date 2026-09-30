#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
int main(){
    string str = "harshit dhakad.";
    for(int i = 0; i < str.length();i++){
        cout << str[i] << " ";
    }
    cout << endl;

    for(char ch : str){
        cout << ch << " ";
    }

    cout << endl;

    reverse(str.begin(),str.end());
    cout << str << endl;
    return 0;
}