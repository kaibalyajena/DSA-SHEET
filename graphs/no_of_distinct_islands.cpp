//the islands coordinates after subtracting from the base and do dfs then store in a set and output the size of the set
class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&island,int initial_row,int initial_col){
        visited[row][col]=1;
        island.push_back({row-initial_row,col-initial_col});
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,visited,island,initial_row,initial_col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> island;
                    dfs(i,j,grid,visited,island,i,j);
                    s.insert(island);
                }
            }
        }
        return s.size();
    }
};
