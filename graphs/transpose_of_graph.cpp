#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
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

void transpose(vector<int> adj[],vector<int> trans[],int vertices){
    for(int i=0;i<vertices;i++){
        for(auto x:adj[i]){
            addEdge(trans,x,i);
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
        addEdge(adj,u,v);
    }
    printGraph(adj,vertices);
    cout<<"Transposed graph"<<endl;
    vector<int> trans[vertices];
    transpose(adj,trans,vertices);
    printGraph(trans,vertices);
    return 0;
}
