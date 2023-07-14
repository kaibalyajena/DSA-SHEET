#include<iostream>
using namespace std;



int main(){
    int vertices;
    int edges;
    cin>>vertices>>edges;
    int adjMat[vertices][vertices];
    //vector<vector<int> > adjMat(vertices,vector<int>(vertices,0));
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            adjMat[i][j]=0;
        }
    }
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}