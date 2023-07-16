#include<iostream>
#include<vector>
using namespace std;

//directed graph
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

//reverse the edges
//if there is a edge from u to v then in the transpose graph add edge between v and u
void transpose(vector<int> adj[],vector<int> trans[],int vertices){
    //iterate over all vertices of the original graph
    for(int i=0;i<vertices;i++){
        //iterate over the adjacent vertices of each vertice
        for(auto x:adj[i]){
            //reverse the edges
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
    //declare the transpose graph
    vector<int> trans[vertices];
    transpose(adj,trans,vertices);
    printGraph(trans,vertices);
    return 0;
}
