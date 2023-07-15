//modified dfs
class Solution {
public:
    void dfs(int s,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[s]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[s][i]==1 && visited[i]==false){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited;
        visited.resize(isConnected.size(),false);
        int provinces=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};



//simple dfs
class Solution {
public:
    void dfs(int s,vector<int> adj[],vector<bool>& visited){
        visited[s]=true;
        for(auto i:adj[s]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited;
        visited.resize(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                provinces++;
            }
        }
        return provinces;
    }
};




//simple bfs
class Solution {
public:
    void bfs(int s,vector<int> adj[],vector<bool>& visited){
        queue<int> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto i:adj[temp]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited;
        visited.resize(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,adj,visited);
                provinces++;
            }
        }
        return provinces;
    }
};