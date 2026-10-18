#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n! * n) - n! permutations, each takes O(n) to print.
// Space Complexity: O(n) - recursion call stack depth of n frames.
void permutatestring(string str,int idx ){
    if(idx == str.length()){
        for(char val : str){
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    for(int i = idx ; i < str.length();i++){
        swap(str[idx], str[i]);
        permutatestring(str,idx +1);
        swap(str[idx], str[i]);
    }
}

int main(){
    string str = "abc";
    permutatestring(str,0);
    return 0;
}