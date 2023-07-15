#include<iostream>
#include<stack>
using namespace std;

void dfs(vector<int> adj[],int vertices,int s){
    vector<bool> visited;
    visited.resize(vertices,false);
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int temp=st.top();
        st.pop();
        if(!visited[temp]){
            cout<<temp<<" ";
            visited[temp]=true;
        }
        for(auto adjacent:adj[temp]){
            if(!visited[adjacent]){
                st.push(adjacent);
            }
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
    dfs(adj,vertices,0);
    return 0;
}