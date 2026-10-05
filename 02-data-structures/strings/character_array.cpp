#include<iostream>
#include<cstring>
using namespace std;

// Time Complexity: O(n)
int main(){
//     char str[] = {'a','b','c'};
//     char str1[] = {'a','b','c','\0'};
//     char str2[] = "hello";
    char str3[100];
    char str4[100];

    // cout << str << endl; 
    // cout << str1 << endl;
    // cout << str2 << endl;
    // cout << strlen(str1) << endl;
    // cout << strlen(str2) << endl;
    // cout << str2[3] << endl;

    // cout << "enter the string " << endl;
    // cin >> str3;
    
    // cout << str3 << endl;

    // cout << "enter the string " << endl;
    // cin.getline (str4,100);
    // cout << str4 << endl;

    cout << "enter the string " << endl;
    cin.getline (str4,100,'$');
    cout << str4 << endl;


    return 0;  
}