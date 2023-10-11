//sort all the edges based on the weight
//then select then edges one by one check if the vertices of the edges have the same ultimate parent and if they have different parent then do the union.
class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    public:
    DisjointSet(int v){
        parent.resize(v);
        rank.resize(v,0);
        for(int i=0;i<v;i++){
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
    void unionByRank(int u,int v){
        int par_u=findUParent(u);
        int par_v=findUParent(v);
        if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }else if(rank[par_v]>rank[par_u]){
            parent[par_u]=par_v;
        }else{
            rank[par_u]++;
            parent[par_v]=par_u;
        }
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adj_node=it[0];
                int weight=it[1];
                edges.push_back({weight,{i,adj_node}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int sum=0;
        for(auto it:edges){
            int weight=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUParent(u)!=ds.findUParent(v)){
                sum+=weight;
                ds.unionByRank(u,v);
            }
            
        }
        return sum;
    }
};