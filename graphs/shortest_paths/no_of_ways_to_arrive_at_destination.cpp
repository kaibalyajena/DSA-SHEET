//modification of djkistras
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        //dist node
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        long long mod=1e9+7;
        while(!pq.empty()){
            long long distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjacent=it.first;
                int weight=it.second;
                if(distance+weight<dist[adjacent]){
                    //when first time min dist is reached
                    dist[adjacent]=distance+weight;
                    pq.push({dist[adjacent],adjacent});
                    ways[adjacent]=ways[node];
                }else if((distance+weight)==dist[adjacent]){
                    //when min dist is reached subsequent times
                    ways[adjacent]=(ways[adjacent]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};