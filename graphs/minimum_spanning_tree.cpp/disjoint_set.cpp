//used to perform 2 operations in constant time
//find 
//union by rank and union by size
//union and find operations take time 4alpha which is costant time
#include<iostream>
using namespace std;

class DisjointSet{
        vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        //path compression in the return statement
        int findUParent(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u]=findUParent(parent[u]);
        }
        void unionByRank(int u, int v){
            int pu=findUParent(u);
            int pv=findUParent(v);
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }else if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same parent"<<endl;
    }else{
        cout<<"don't have the same parent"<<endl;
    }
    ds.unionByRank(3,7);
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same parent"<<endl;
    }else{
        cout<<"don't have the same parent"<<endl;
    }
    return 0;
}