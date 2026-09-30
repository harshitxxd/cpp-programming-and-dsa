#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
int main(){
    string str = "apna college";
    cout << str << endl;

    getline(cin,str);
    cout << str << endl;

    string str1 = "hello";
    string str2 ="world";
    string str3 = str1 + str2;
    cout << str3 << endl;
    cout << (str1 == str2 ) << endl;
    cout << str1.length() << endl;
    return 0;
}