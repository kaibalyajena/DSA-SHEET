//just a simple topological sort after making the adjacency list
class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& preq) {
        vector<int> adj[v];
        vector<int> indegree(v,0);
        for(auto i:preq){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto adjacent:adj[node]){
                indegree[adjacent]--;
                if(indegree[adjacent]==0){
                    q.push(adjacent);
                }
            }
        }
        if(topo.size()!=v){
            topo.clear();
        }
        return topo;
    }
};