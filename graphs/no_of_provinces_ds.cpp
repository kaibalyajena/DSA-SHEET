//basically we neeed to count the number of connected components in a graph
//so we will use disjoint set data structure in order to do so
//if there is a edge between 2 vertices then we would do a union so that they become in the same components
//then to find the answer we need to find the no of distinct ultimate parents or edges which have same ultimate parent as itself

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int x){
        parent.resize(x);
        size.resize(x,0);
        for(int i=0;i<x;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u){
            return u;
        }else{
            return parent[u]=findUParent(parent[u]);
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
            size[pu]++;
        }else{
            parent[pu]=pv;
            size[pv]++;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        return count;
    }
};