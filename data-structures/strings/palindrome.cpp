#include<iostream>
#include<string>
 using namespace std;

// Time Complexity: O(n)
 int main(){
    string str ="racecar";
    bool ispalindrome = true ;
    int st = 0, end = str.length() -1;
    while (st <= end){
        if (str[st] != str[end]){
            ispalindrome = false ;
        }
        st ++;
        end --;
    }
    if (ispalindrome){
        cout << "the string is palindrome ";
    }
    else {
        cout << " not a palindrome";
    }
    return 0 ;
}

