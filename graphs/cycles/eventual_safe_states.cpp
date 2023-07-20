//any node which is part of a cycle or has an outgoing edge to any node present in the cycle can never be a safe node

//basic code is same as detecting cycle in a directed graph
class Solution {
public:
    bool dfs(int s,vector<int>& visited,vector<int>& recStack,vector<int>& checkSafe,vector<vector<int>>& graph){
        visited[s]=1;
        recStack[s]=1;
        for(auto adjacent:graph[s]){
            if(!visited[adjacent]){
                if(dfs(adjacent,visited,recStack,checkSafe,graph)){
                    return true;
                }
            }else if(recStack[adjacent]==1){
                return true;
            }
        }
        //if vertice s did not return true in the above recursion calls meaning it is not a part of cycle of connected to a cycle so it becomes a safe node
        checkSafe[s]=1;
        recStack[s]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> visited(v,0);
        vector<int> recStack(v,0);
        vector<int> checkSafe(v,0);
        vector<int> safeNodes;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,visited,recStack,checkSafe,graph);
            }
        }
        for(int i=0;i<v;i++){
            if(checkSafe[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};








//using topological sort
//topo sort works on the concept of indegree and start with nodes with indegree 0 but safe terminal nodes have outdegree of 0.
//so we need to first reverse the edges and and do topo sort and in the end the elements in array would be the safe nodes and we must sort them if asked in the problem 
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(auto adjacent:graph[i]){
                adj[adjacent].push_back(i);
            }
        }
        vector<int> indegree(v,0);
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<v;i++){
            for(auto adjacent:adj[i]){
                indegree[adjacent]++;
            }
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
        sort(topo.begin(),topo.end());
        return topo;
    }
};