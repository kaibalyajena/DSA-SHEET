// it is not applicable for graphs having negative weight cycles

//we are using using a min heap data structure implemented using a priority queue
//in the pq weight store the dist to reach that node from source and the node in a pair
//we iterate through the adjacent nodes and relax it. if we find a shorter distance to a node from the source we update it and push it into the priority queue
//tc E*log(V)
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        //dist,edge
        pq.push({0,S});
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjacent=it[0];
                int weight=it[1];
                if(distance+weight<dist[adjacent]){
                    dist[adjacent]=distance+weight;
                    pq.push({dist[adjacent],adjacent});
                }
            }
        }
        return dist;
    }
};







//using set
//same some extra iterations but erase operation takes log n time
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        s.insert({0,S});
        while(!s.empty()){
            auto it=*(s.begin());
            int node=it.second;
            int distance=it.first;
            s.erase({distance,node});
            for(auto pt:adj[node]){
                int weight=pt[1];
                int adjacent=pt[0];
                if(distance+weight<dist[adjacent]){
                    s.erase({dist[adjacent],adjacent});
                    dist[adjacent]=distance+weight;
                    s.insert({dist[adjacent],adjacent});
                }
            }
        }
        return dist;
    }
};