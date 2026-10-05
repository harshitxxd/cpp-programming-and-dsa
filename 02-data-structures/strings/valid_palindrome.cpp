#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
class solution{
    public :
    bool isalphanumeric(char ch){
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }

        return false;
    }
    bool isPalindrome(string s) {
        int st = 0 , end = s.length() -1;
        while (st <= end){
            if(!isalphanumeric(s[st])){
                st ++;
                continue;
            }
            if (!isalphanumeric(s[end])){
                end --;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true ;
    }
};

int main(){
    solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s) << endl;;
    return 0;
}