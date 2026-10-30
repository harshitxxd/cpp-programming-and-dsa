#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class graph{
    int v ;
    list<int>* l;

    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u ,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool iscycleundfs(int src, int par , vector<bool>&vis){
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(iscycleundfs(v,src,vis)){
                    return true;
                }
            }else if(v != par){
                return true;
            }
        }
        return false;
    }
    bool is_cycle(){
        vector<bool> vis(v,false);
        for(int i =0;i < v ;i++){
            if(!vis[i]){
                if(iscycleundfs(i,-1, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool iscycleunbfs(int src , vector<bool>&vis ){
        queue<pair<int,int>>  q;

        q.push({src,-1});
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front().first;
            int paru = q.front().second;
            q.pop();

            list<int>neighbors = l[u];
            for (int v : neighbors){
                if(!vis[v]){
                    q.push({v,u});
                    vis[v] = true;
                }else if (v != paru){
                    return true ;
                }
            }
        }
        return false ;
    }

    bool iscylce(){
        vector<bool> vis(v,false);

        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                if(iscycleunbfs(i,vis)){
                    return true;
                }
            }
        }
        return false ;
    }
};

int  main(){
    graph g(5);

    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(3,4);

    cout <<"dfs : " << g.is_cycle()<< endl;
    cout << "bfs : " << g.iscylce() << endl;
    return 0;
}