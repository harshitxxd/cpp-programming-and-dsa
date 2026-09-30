#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
int main(){

    vector<int> vec = {2,3,6,7,4,8,9,5};

    reverse(vec.begin(),vec.end());
    for (int val : vec){
        cout << val << " " ;
    }

    cout << endl;
    
    reverse(vec.begin() +1,vec.begin()+5);
    for (int val : vec){
        cout << val << " " ;
    }
    cout << endl;

    string s = "abcdef";
    string s1 ="abcdef";
    next_permutation(s.begin(),s.end());
    prev_permutation(s1.begin(),s1.end());
    cout << s << endl;
    cout << s1 << endl;

    cout << max(4,5) << " " << min(3,5) << endl;
    cout << *max_element(vec.begin(),vec.end()) << endl;
    cout << *min_element(vec.begin(),vec.end()) << endl;

    vector<int> vec1 = {1,2,3,4,5};
    cout << binary_search(vec1.begin(),vec1.end(),3) << endl;

    int a = 5, b= 10;
    swap(a,b);
    cout << a << " " << b << endl;


 
    return 0;
}