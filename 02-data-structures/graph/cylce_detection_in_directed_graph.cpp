#include<iostream>
#include<vector>
#include<list>
#include <queue>
#include<stack>
using namespace std;

class graph{
    int v ;
    list<int> *l;

    public :
    graph (int v){
        this -> v = v;
        l = new list<int> [v];
    }

    void addedge(int u , int v){
        l[u].push_back(v);
    }

    bool iscycledirdfs(int curr, vector<bool>&vis, vector<bool> &repath){
        vis[curr] = true ;
        repath[curr]= true ;

        for( int v : l[curr]){
            if(!vis[v]){
                if(iscycledirdfs(v,vis,repath)){
                    return true ;
                }
            }
            else if(repath[v]){
                return true ;
            }
        }
        repath[curr] = false ;
        return false ;
    }

    bool iscyclic(){
        vector<bool> vis(v, false);
        vector<bool> repath(v, false);

        for(int i = 0; i < v; i++){
            if(!vis[i] && iscycledirdfs(i, vis, repath)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    graph g(4);

    g.addedge(1,0);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(3,0);

    if(g.iscyclic()){
        cout << "Cycle detected in directed graph" << endl;
    }
    else{
        cout << "No cycle detected" << endl;
    }

    return 0;
}