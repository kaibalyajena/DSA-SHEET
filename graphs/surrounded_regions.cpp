//perform dfs on the border 0 and then replace the non visited 0 to X
class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(board,vis,0,j);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(board,vis,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(board,vis,i,0);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(board,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};