//helps to identify negative weight cycles
//applicable for only directed graphs //undirected graph must be converted into a directed graph
//single source shorted path
//need to relax all the edges vertices-1 times sequencially
//in worst case it will take n-1 edges to reach from the first to the last node hence at most to detect a negative weight cycle we will need to relax n-1 times
//if at the n th iteration the dist array values still change then we have found the negative weight cycle
//tc v*e
class Solution {
  public:
   
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int weight=it[2];
                if(dist[u]+weight<dist[v] && dist[u]!=1e8){
                    dist[v]=dist[u]+weight;
                }
            }
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            if(dist[u]+weight<dist[v] && dist[u]!=1e8){
                return {-1};
            }
        }
        return dist;
    }
};