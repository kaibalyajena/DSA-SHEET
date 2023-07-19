//just doing topo sort for cycle detection bfs. if topo sort correct then all tasks can be completed keeping int mind the prerequisites.
class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& preq) {
        vector<int> adj[v];
        vector<int> indegree(v,0);
        vector<int> topo;
        queue<int> q;
        for(auto it:preq){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
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
        if(topo.size()==v){
            return true;
        }
        return false;
    }
};


//just to detection of cycle in directed graph using dfs
class Solution {
public:
    bool dfs(int s,vector<int>&visited,vector<int>&recStack,vector<int> adj[]){
        visited[s]=1;
        recStack[s]=1;
        for(auto adjacent:adj[s]){
            if(!visited[adjacent]){
                if(dfs(adjacent,visited,recStack,adj)){
                    return true;
                }
            }else if(recStack[adjacent]==1){
                return true;
            }
        }
        recStack[s]=0;
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& preq) {
        vector<int> adj[v];
        vector<int> visited(v,0);
        vector<int> recStack(v,0);
        for(auto it:preq){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(i,visited,recStack,adj)==true){
                    return false;
                }
            }
        }
        return true;
    }
};