#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        //way to declare a 2d matrix  ([][] replaced with **)
        bool** tc;
        //wasy to delare an array of type list of type int ([] replaced with *)
        list<int>* adj;
        void dfs(int u,int v);
    public:
        Graph(int v);
        void addEdge(int u,int v){
            adj[u].push_back(v);
        }
        void transitiveClosure();
};

Graph::Graph(int v){
    this->v=v;
    //initialize the array in heap memory
    adj=new list<int>[v];
    //making the 2d array
    //making a array named tc (transitive closure) of type bool* (each element will be an array of bools)
    tc=new bool*[v];
    //at every index make that boolean array
    for(int i=0;i<v;i++){
        //making boolean array at index i of tc
        tc[i]=new bool[v];
        //initial the entire array as false
        // array name , initializing value , size of the array
        memset(tc[i],false,v*sizeof(bool));
    }
}

void Graph::dfs(int u,int v){
    //making v reachable from u (there is a direct edge or indirect path from u to v or u and v are same vertex)
    tc[u][v]=true;
    //traverse all the adjacent vertices of the destination 
    //because if adjacent vertex is reachable from destination v then it is also reachable from the source u as a indirect path (u->v->adjacent vertex)
    for(auto x:adj[v]){
        //check if source to adjacent of dest is not updated in the transitive closure
        if(tc[u][x]==false){
            //if they are same vertex then mark as true else if they are different vertices then call dfs for them
            if(u==x){
                tc[u][x]=true;
            }else{
                dfs(u,x);
            }
        }
    }
}

//makes the reachability matrix
void Graph::transitiveClosure(){
    //every vertex is reachable from itself so we do dfs of all vertices with the same vertex as source and dest
    for(int i=0;i<v;i++){
        dfs(i,i);
    }
    //printing the transitive closure / reachability matrix
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}