#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class edge{
    public:
    int u, v, wt;

    edge(int u,int v,int wt){
        this -> u = u;
        this -> v = v;
        this -> wt = wt;
    }
    bool operator<(const edge &other) const {
        return this -> wt < other.wt;
    }
};

class graph {
    public :
    int v;
    vector<edge> edges ;
    vector<int>par,rank;

    graph(int v){
        this -> v = v;

        for (int i = 0 ; i < v ; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addedge(int u, int v , int wt){
        edges.push_back(edge(u,v,wt));
    }

    int find (int x){
        if(par[x] == x){
            return x ;
        }
        return par[x] = find(par[x]);
    }

    void unionbyrank(int a, int b){
        int para = find(a);
        int parb = find(b);

        if(para == parb) return;

        if(rank[para] == rank[parb]){
            par[parb] = para;
            rank[para]++;
        }else if(rank[para] > rank[parb]){
            par[parb] = para;
        }else {
            par[para] = parb;
        }
    }

    void kruskal(){
        sort(edges.begin(),edges.end());
        int mstcost = 0;
        int count  = 0;
        for (int i = 0 ; i < edges.size() && count < v-1; i++){
            edge e = edges[i];

            int paru = find(e.u);
            int parv = find(e.v);

            if(paru != parv){
                unionbyrank(e.u,e.v);
                mstcost += e.wt;
                count++;
            }
        }

        cout << "mstcost : " << mstcost << endl;
    }
};

int main(){
    graph graph(4);

    graph.addedge(0,1,10);
    graph.addedge(0,2,6);
    graph.addedge(0,3,5);
    graph.addedge(1,3,15);
    graph.addedge(2,3,4);

    graph.kruskal();

    return 0;
}