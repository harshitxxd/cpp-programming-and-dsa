#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    pair<int,int> p = {1,2};

    cout << p.first << endl;
    cout << p.second << endl;

    pair<char,int> p1 = {'c',2};

    cout << p1.first << endl;
    cout << p1.second << endl;

    pair<int,pair<int,int>> p2= {1,{1,2}};

    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;

    cout << endl;

    vector<pair<int,int>> vec = {{1,2},{3,4},{5,6}};
    vec.push_back({7,8});
    vec.emplace_back(9,10);
    for(auto p : vec){
        cout << p.first << " " << p.second << endl;

    }
    return 0;
}