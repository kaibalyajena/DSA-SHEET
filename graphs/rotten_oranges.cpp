//using bfs
class Solution {
public:
    bool checkFresh(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return true;
                }
            }
        }
        return false;
    }
    void bfs(vector<vector<int>>& grid,int &ans){
        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }else{
                    visited[i][j]=0;
                }
            }
        }
        int deltarow[]={-1,0,0,+1};
        int deltacol[]={0,-1,+1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            ans=max(ans,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+deltarow[i];
                int ncol=col+deltacol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                    grid[nrow][ncol]=2;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(!checkFresh(grid)){
            return 0;
        }
        int ans=0;
        bfs(grid,ans);
        if(checkFresh(grid)==true){
            return -1;
        }
        return ans;
    }
};