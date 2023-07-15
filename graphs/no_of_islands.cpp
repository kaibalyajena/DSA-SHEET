//bfs sol
class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int deltaRow=-1;deltaRow<=1;deltaRow++){
                for(int deltaCol=-1;deltaCol<=1;deltaCol++){
                    // remove this condition to check for all 8 directions. (it checks for only 4 directions)
                    if(abs(deltaRow+deltaCol)==1){ 
                        int new_row=row+deltaRow;
                        int new_col=col+deltaCol;
                        if(new_row>=0 && new_col>=0 && new_row<n && new_col<m && !visited[new_row][new_col] && grid[new_row][new_col]=='1'){
                            visited[new_row][new_col]=1;
                            q.push({new_row,new_col});
                    }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    bfs(row,col,grid,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};



//dfs sol
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        for(int deltarow=-1;deltarow<=1;deltarow++){
            for(int deltacol=-1;deltacol<=1;deltacol++){
                if(abs(deltarow+deltacol)==1){
                    int nrow=row+deltarow;
                    int ncol=col+deltacol;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                        dfs(nrow,ncol,grid,visited);
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    dfs(row,col,grid,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};




//best sol
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int m, int n, int i, int j ){
        if(i < 0 || i >= m || j<0 || j>=n || grid[i][j] == '0')   return ;
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            DFS(grid,m,n,i-1,j);
            DFS(grid,m,n,i+1,j);
            DFS(grid,m,n,i,j+1);
            DFS(grid,m,n,i,j-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0 , n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    DFS(grid,n,m,i,j);
                }
            }
        }

        return ans;
    }
};