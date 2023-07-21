//do topo sort using dfs and while removing element from the stack do relaxation of edges.
class Solution {
  public:
     void topoSort(int s,vector<pair<int,int>> adj[],vector<int>& visited,stack<int>& st){
         visited[s]=1;
         for(auto adjacent:adj[s]){
            if(!visited[adjacent.first]){
                topoSort(adjacent.first,adj,visited,st);
            }
         }
         st.push(s);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> visited(N);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                topoSort(i,adj,visited,st);
            }
        }
        vector<int> dist(N,1e9);
        dist[0]=0;
        // stack runs n times times  tc(N+E) which is better than djikstras algo so if we know there are no cycle use this method
        //by doing topo sort we are saving the no of times we have to do relaxation
        while(!st.empty()){
            int node=st.top();
            st.pop();
            //runs for no of edges times
            for(auto adjacent:adj[node]){
                int v=adjacent.first;
                int wt=adjacent.second;
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
