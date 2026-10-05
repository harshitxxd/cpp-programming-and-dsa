#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n)
int main(){
    vector<int> vec = {1,2,3,4,5};
    vec.push_back(6) ;
    vec.pop_back();
    cout << vec.at(2) << endl;
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    vec.erase(vec.begin());
    vec.erase(vec.begin(),vec.begin()+2);
    vec.insert(vec.begin()+3,5);
    vec.clear();
    cout << vec.empty() << endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    // iterator
    // vector<int>::iterator it ;
    // for (it = vec.begin();it != vec.end();it++){
    //         cout << *it << endl;
    // }

    // cout << endl;

    // vector<int>::reverse_iterator rit;
    // for(rit = vec.rbegin() ; rit != vec.rend(); rit++){
    //     cout << *rit << endl;
    // }

    // cout << endl;

    for ( auto it = vec.begin();it != vec.end();it++){
            cout << *it << endl;
    }

    cout << endl ;

    for(auto it = vec.rbegin() ; it != vec.rend();it++){
        cout << *it << endl;
    }

    return 0;
}