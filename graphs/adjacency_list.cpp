#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int vertices){
    for(int i=0;i<vertices;i++){
        cout<<i<<": ";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices;
    int edges;
    cin>>vertices>>edges;
    vector<int> adjList[vertices];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adjList,u,v);
    }
    printGraph(adjList,vertices);
    return 0;
}