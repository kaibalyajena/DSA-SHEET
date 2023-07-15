#include<iostream>
using namespace std;

void dfsRec(vector<int> adj[],int s,vector<bool> &visited){
    cout<<s<<" ";
    visited[s]=true;
    for(auto adjacent:adj[s]){
        if(!visited[adjacent]){
            dfsRec(adj,adjacent,visited);
        }
    }
}

void dfs(vector<int> adj[],int vertices){
    vector<bool> visited;
    visited.resize(vertices,false);
    dfsRec(adj,0,visited);
    for(auto i:visited){
        if(i==false){
            dfsRec(adj,i,visited);
        }
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int> adj[vertices];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,vertices);
    return 0;
}