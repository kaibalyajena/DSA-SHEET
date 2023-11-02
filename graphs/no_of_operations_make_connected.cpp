// we will use disjoint set datastructure
// we will one by one do the union of the vertices of the graph who have an edge in between them
// if both the vertices having edge between them already have the same ultimate parent then the edge is an extra edge
// then we count the number of connected components
// and if we have extra edges greater than or equal to edges required to make the connected graph (no of connected components - 1) then we have the answer


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
            size[pv]++;
        }else{
            parent[pu]=pv;
            size[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra_edges=0;
        for(auto i:connections){
            if(ds.findUParent(i[0])==ds.findUParent(i[1])){
                extra_edges++;
                continue;
            }
            ds.unionBySize(i[0],i[1]);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                components++;
            }
        }
        if(components-1<=extra_edges){
            return components-1;
        }else{
            return -1;
        }
    }
};