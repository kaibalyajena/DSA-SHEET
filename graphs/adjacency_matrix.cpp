#include<iostream>
using namespace std;



int main(){
    int vertices;
    int edges;
    cin>>vertices>>edges;
    //creating the adjacency matrix of size vertices*vertices
    int adjMat[vertices][vertices];
    //vector<vector<int> > adjMat(vertices,vector<int>(vertices,0));
    //initializing the adjacency matrix element to 0. (no edges in the graph)
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            adjMat[i][j]=0;
        }
    }
    //taking input of all the edges present in the graph
    for(int i=0;i<edges;i++){
        int u,v;
        //input the vertices who have an edge between them
        cin>>u>>v;
        //represent the edge between vertices by putting them as 1 in adjacency matrix
        //only first line is necessary for directed graph
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    //printing the adjacency matrix
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}