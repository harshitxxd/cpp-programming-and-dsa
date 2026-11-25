#include<iostream>
#include<vector>
using namespace std;

class disjointsetunion{
    public:
    int n;
    vector<int> par , rank ;

    disjointsetunion(int n){
        this ->n = n;

        for(int i = 0; i < n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unionbyrank(int A, int B){
        int parA = find(A);
        int parB = find(B);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else {
            par[parA] = parB;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void getinfo (){
        for(int i = 0;i < n;i++){
            cout << par[i] << " ";
        }
        cout << endl;

         for(int i = 0;i < n;i++){
            cout << rank[i] << " ";
        }
        cout << endl;
    }

};

int main (){
    disjointsetunion dsu(6);

    dsu.unionbyrank(0,2);
    cout << dsu.find(2) << endl;

    dsu.unionbyrank(1,3);
    dsu.unionbyrank(2,5);
    dsu.unionbyrank(0,3);
    cout << dsu.find(2) << endl;

    dsu.unionbyrank(0,4);

    dsu.getinfo();

    return 0;
}
