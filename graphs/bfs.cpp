#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        //storing the no if vertices and the adjacency list as private
        int v;
        //a vector containing a list at each index
        vector<list<int> > adj;
    public:
        //the constructor , adding edge and bfs function is public
        Graph(int v);
        void addEdge(int src,int dest);
        void bfs(int s);
};

Graph::Graph(int v){
    //set no. of vertices which is private
    this->v=v;
    //defining the size of the vector repesenting adjacency list as no. of vertices
    adj.resize(v);
}

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::bfs(int s){
    //making a visited array
    vector<bool> visited;
    //initializing its size and default value as false
    visited.resize(v,false);
    //declaring a queue
    queue<int> q;
    //pushing the source into queue and markig it as visited
    q.push(s);
    visited[s]=true;
    //run the loop until the queue is empty
    while(!q.empty()){
        //get the front element of the queue (first in first out)
        int temp=q.front();
        //remove the front element
        q.pop();
        //print the front element
        cout<<temp<<" ";
        //iterate over all the vertices who have an edge with the front vertex (iterate all adjacent vertices)
        for(auto adjacent:adj[temp]){
            //if adjacent vertex is not visited
            if(!visited[adjacent]){
                //push it into queue and mark it as visited
                q.push(adjacent);
                visited[adjacent]=true;
            }
        }
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    //making object g of class graph and triggering the constructor by passing the no. of vertices
    Graph g(vertices);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    //calling the bfs function and passing the source
    g.bfs(0);
    return 0;
}                                                                               