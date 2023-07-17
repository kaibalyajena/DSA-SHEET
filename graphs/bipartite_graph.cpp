//cannot have odd length cycle
//can be colored using only 2 colors
//linear graph with no cycles is always bipartite


//using bfs
//whenever we find an adjacent node which is already colored and has the same color with it's adjacent node we return false
class Solution {
public:
    bool bfs(vector<vector<int>>&graph,vector<int>&color,int s){
        queue<int> q;
        q.push(s);
        color[s]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacent:graph[node]){
                if(color[adjacent]==-1){
                    color[adjacent]=color[node]^1;
                    q.push(adjacent);
                }else if(color[adjacent]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!bfs(graph,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
};