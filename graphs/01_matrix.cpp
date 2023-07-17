class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int drow[]={0,0,-1,1};
        int dcol[]={1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            ans[row][col]=dist;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return ans;
    }
};