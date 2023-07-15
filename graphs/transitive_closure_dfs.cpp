#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        bool** tc;
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
    adj=new list<int>[v];
    tc=new bool*[v];
    for(int i=0;i<v;i++){
        tc[i]=new bool[v];
        memset(tc[i],false,v*sizeof(bool));
    }
}

void Graph::dfs(int u,int v){
    tc[u][v]=true;
    for(auto x:adj[v]){
        if(tc[u][x]==false){
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
    for(int i=0;i<v;i++){
        dfs(i,i);
    }
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