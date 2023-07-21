//just a simple bfs implementation where we push the adjacent in the queue not because of the visited logic but because if its distance is updated.
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(N,INT_MAX);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacent:adj[node]){
                if(dist[node]+1<dist[adjacent]){
                    dist[adjacent]=dist[node]+1;
                    q.push(adjacent);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};