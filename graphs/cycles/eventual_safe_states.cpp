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
