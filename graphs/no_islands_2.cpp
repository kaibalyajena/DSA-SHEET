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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans;
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        int count=0;
        int drow[4]={0,1,-1,0};
        int dcol[4]={1,0,0,-1};
        for(auto it:operators){
            int i=it[0];
            int j=it[1];
            if(!visited[i][j]){
                visited[i][j]=1;
                grid[i][j]=1;
                count++;
                for(int del=0;del<4;del++){
                    int nrow=i+drow[del];
                    int ncol=j+dcol[del];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && ds.findUParent((nrow*m)+ncol)!=ds.findUParent((i*m)+j)){
                        count--;
                        ds.unionBySize((i*m)+j,(nrow*m)+ncol);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};