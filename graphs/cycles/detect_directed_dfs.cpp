//to detect a cyle the already visited node must be visited again on the same path. we keep track of the current path using recurision call stack

class Solution {
  public:
    bool dfs(int s,vector<int>&visited,vector<int>&recStack,vector<int> adj[]){
        //mark s as visited and put it inside the recursion call stack
        visited[s]=1;
        recStack[s]=1;
        for(auto adjacent:adj[s]){
            //if adjacent is not visited then do dfs for it
            if(!visited[adjacent]){
                if(dfs(adjacent,visited,recStack,adj)){
                    return true;
                }
            }else if(recStack[adjacent]){//if adjacent is visited and also inside the recursion call stack meaning it was visited in the current path/traversal hence we have found a cycle
                return true;
            }
        }
        //after the recursion(dfs for all adjacent not visited) for s is over remove it from the recursion call stack
        recStack[s]=0;
        //as no cycle found return false
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> recStack(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,recStack,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

