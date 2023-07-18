//topological sorts only works on acyclic graph means if the topo sort does not work properly meaning all the vertices are present inside the topo array then the graph has a cycle.


class Solution {
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> indegree(V,0);
       for(int i=0;i<V;i++){
           for(auto adjacent:adj[i]){
               indegree[adjacent]++;
           }
       }
       vector<int> topoSort;
       queue<int> q;
       for(int i=0;i<V;i++){
           if(indegree[i]==0){
               q.push(i);
           }
       }
       while(!q.empty()){
           int node=q.front();
           topoSort.push_back(node);
           q.pop();
           for(auto adjacent:adj[node]){
               indegree[adjacent]--;
               if(indegree[adjacent]==0){
                   q.push(adjacent);
               }
           }
       }
       //if all the vertices are present in the topo sort means that it worked properly and graph does not have a cycle
       if(topoSort.size()==V){
           return false;
       }
       return true;
    }
};