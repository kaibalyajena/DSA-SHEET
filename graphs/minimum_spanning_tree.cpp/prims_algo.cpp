//mst is a tree in which we have n nodes and n-1 edges and all nodes are reachable from each other
//the intuition is greedy
//tc e log e
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> visited(V,0);
        // weight is first we want the min weight at the top by using the min heap datastructure
        // weight node
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=1;
            sum+=weight;
            for(auto it:adj[node]){
                int adjacent=it[0];
                int adj_weight=it[1];
                if(!visited[adjacent]){
                    pq.push({adj_weight,adjacent});
                }
            }
        }
        return sum;
    }
};