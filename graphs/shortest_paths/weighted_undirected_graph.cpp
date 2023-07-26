//DO DIJKSTRA'S ALGORITHM AND MAINTAIN A PARENT ARRAY ALONG WITH THAT WHICH WOULD BE TRAVERSED LATER
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            int weight=edges[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        vector<int> parent(n,-1);
        vector<int> ans;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjacent=it.first;
                int weight=it.second;
                if(weight+distance<dist[adjacent]){
                    dist[adjacent]=weight+distance;
                    parent[adjacent]=node;
                    pq.push({dist[adjacent],adjacent});
                }
            }
        }
        int node=n-1;
        while(parent[node]!=-1){
            ans.push_back(node+1);
            node=parent[node];
        }
        if(node!=0){
            ans.clear();
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};