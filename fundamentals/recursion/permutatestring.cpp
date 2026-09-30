#include<iostream>
#include<string>
using namespace std;

void permutatestring(string str,int idx ){
    if(idx == str.length()){
        for(char val : str){
            cout << str[val] << " ";
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