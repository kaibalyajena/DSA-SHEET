//used to perform 2 operations in constant time
//find 
//union by rank and union by size
//union and find operations take time 4alpha which is costant time
#include<iostream>
using namespace std;

class DisjointSet{
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
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
            if(pu==pv){
                return;
            }
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }else if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        void unionBySize(int u,int v){
            int pu=findUParent(u);
            int pv=findUParent(v);
            if(pu==pv){
                return;
            }
            if(size[pu]>size[pv]){
                parent[pv]=pu;
                size[pu]+=size[pv];
            }else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same parent"<<endl;
    }else{
        cout<<"don't have the same parent"<<endl;
    }
    ds.unionBySize(3,7);
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same parent"<<endl;
    }else{
        cout<<"don't have the same parent"<<endl;
    }
    return 0;
}