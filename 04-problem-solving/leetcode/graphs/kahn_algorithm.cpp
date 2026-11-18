#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class graph{
    int v;
    list<int>*l;

    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v){
        l[u].push_back(v);
    }

    void toposort(){
        vector<int> res;

        vector<int>indeg(v,0);
        for(int u = 0;u < v ;u++){
            for (int v : l[u]){
                indeg[v]++;
            }
        }

        queue<int>q;
        for(int i = 0 ; i < v ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v:l[curr]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        for (int val:res){
            cout << val << " ";
        }
        cout << endl;
    }
};

int main(){

    graph g(6);
    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,2);

    g.toposort();
    return 0;

}