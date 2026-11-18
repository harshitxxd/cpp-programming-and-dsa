#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class edge{
    public:
    int v;
    int vt;

    edge(int v,int vt){
        this->v = v;
        this->vt = vt;
    }
};

void djksra(int src, vector<vector<edge>>g, int v){
    vector<int>dist(v,INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({0,src});

    while (pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        for(edge e : g[u]){
            if(dist[e.v] > dist[u] + e.vt){
                dist[e.v] = dist[u] + e.vt;
                pq.push({dist[e.v],e.v});
            }
        }
    }

    for (int i = 0 ; i < v ;i++){
         cout << dist[i] << " ";
    }
    cout << endl;
}

int main(){
    int v = 6;
    vector<vector<edge>> g(v);

    g[0].push_back(edge(1,2));
    g[0].push_back(edge(2,4));

    g[1].push_back(edge(2,1));
    g[1].push_back(edge(3,7));

    g[2].push_back(edge(4,3));

    g[3].push_back(edge(5,1));

    g[4].push_back(edge(3,2));
    g[4].push_back(edge(5,5));

    djksra(0,g,v);

    return 0;
}