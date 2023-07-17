//using bfs
class Solution {
  public:
    bool bfs(int s,vector<int> adj[],vector<int> &visited){
        visited[s]=1;
        queue<pair<int,int>> q;
        q.push({s,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x]=1;
                    q.push({x,node});
                }// if we find a already visited node who is not the parent then cycle exists
                else if(parent!=x){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited;
        visited.resize(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
};





//using dfs
class Solution {
  public:
    bool dfs(int s,int parent,vector<int> adj[],vector<int> &visited){
       visited[s]=1;
       for(auto x:adj[s]){
           if(!visited[x]){
               if(dfs(x,s,adj,visited)){
                   return true;
               }
           }else if(parent!=x){
               return true;
           }
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited;
        visited.resize(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
};