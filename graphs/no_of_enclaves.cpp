// do dfs of boundry ones then count no of ones in grid
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        grid[row][col]=0;
        int drow[]={0,0,-1,1};
        int dcol[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                dfs(grid,nrow,ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(grid,0,j);
            }
            if(grid[n-1][j]==1){
                dfs(grid,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};