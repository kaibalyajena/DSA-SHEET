#include<iostream>
#include<vector>
using namespace std;

//adjacency list is a array of vectors/lists. (each element of the array is a vector having all the neighboring vertices connected through an edge with the vertex no. (index of the array))

//for undirected graph
// adding v to adjacency list of u and vica versa if they have a edge between them (neighbors)
//for directed graph only the first line
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//printing the adjacency list
void printGraph(vector<int> adj[],int vertices){
    //traverse all the vertices
    for(int i=0;i<vertices;i++){
        //print the vertex no
        cout<<i<<": ";
        for(auto x:adj[i]){
            //print all vertexes present in the adjacency list of the current vertex i. (printing all those vertices which have an edge with vertex i)
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices;
    int edges;
    cin>>vertices>>edges;
    //creating adjacency list of size no. of vertices
    vector<int> adjList[vertices];
    //take input of all the edges
    for(int i=0;i<edges;i++){
        int u,v;
        //take input of the vertices who have an edge between them
        cin>>u>>v;
        //add edge between them
        addEdge(adjList,u,v);
    }
    //print the adjacency list
    printGraph(adjList,vertices);
    return 0;
}