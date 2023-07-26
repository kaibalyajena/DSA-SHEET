//just count no of components if enough edges are present
class Solution {
public:
    void dfs(int s,vector<int>&visited,vector<int> adj[]){
        visited[s]=1;
        for(auto adjacent:adj[s]){
            if(!visited[adjacent]){
                dfs(adjacent,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1){
            return -1;
        }
        vector<int> adj[n];
        for(int i=0;i<edges;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count-1;
    }
};