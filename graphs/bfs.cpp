#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        vector<list<int> > adj;
    public:
        Graph(int v);
        void addEdge(int src,int dest);
        void bfs(int s);
};

Graph::Graph(int v){
    this->v=v;
    adj.resize(v);
}

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::bfs(int s){
    vector<bool> visited;
    visited.resize(v,false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto adjacent:adj[temp]){
            if(!visited[adjacent]){
                q.push(adjacent);
                visited[adjacent]=true;
            }
        }
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    Graph g(vertices);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.bfs(0);
    return 0;
}                                                                               