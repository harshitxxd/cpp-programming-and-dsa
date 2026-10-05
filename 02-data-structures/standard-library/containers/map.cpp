#include<iostream>
#include<map>
using namespace std;

// Time Complexity: O(n)
int main(){

    map<string,int> m;

    m["tv"] = 100;
    m["laptop"] = 50;
    m["hadphones"] = 50;

    m.insert({"camera", 25});
    m.emplace("mouse" ,40);
    m.erase("tv");
    for(auto p : m){
        cout << p.first << " " << p.second << endl;     
    }

    if(m.find("camera") != m.end()){
        cout << "found " << endl;
    }
    else{
        cout << "not found" << endl;
    }


    cout << m.count("laptop") << endl; 

    cout <<  endl;

    multimap<string,int> m1;

    m1.emplace("tv", 100);
    m1.emplace("tv", 100);
    m1.emplace("tv", 100);
    m1.emplace("tv", 100);

    m1.erase(m1.find("tv"));

    for(auto p1 : m1){
        cout << p1.first << " " << p1.second << endl;     
    }


    return 0;
}