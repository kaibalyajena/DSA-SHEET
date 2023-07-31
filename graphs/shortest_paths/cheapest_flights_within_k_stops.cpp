//modification of djkistra's algorithm
//we are using queue instead of a priority queue because we are increasing stops by 1 each time 
//and that this is main criteria of selecting the next front element 
//so as it is already being added to the queue in a sorted order 
//so no need for a priority queue to sort them on the basis of stops saving us time
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<vector<int>> q;
        // stops node dist
        q.push({0,src,0});
        while(!q.empty()){
            int stops=q.front()[0];
            int node=q.front()[1];
            int distance=q.front()[2];
            q.pop();
            if(stops==k+1){
                continue;
            }
            for(auto it:adj[node]){
                int adjacent=it.first;
                int weight=it.second;
                if(distance+weight<dist[adjacent]){
                    dist[adjacent]=distance+weight;
                    q.push({stops+1,adjacent,dist[adjacent]});
                }
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};