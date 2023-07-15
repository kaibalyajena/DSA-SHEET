//using dfs
class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int original_color,int n,int m,int color){
        if(row<0 || col<0 || row==n || col==m || image[row][col]!=original_color){
            return;
        }
        image[row][col]=color;
        dfs(image,row+1,col,original_color,n,m,color);
        dfs(image,row-1,col,original_color,n,m,color);
        dfs(image,row,col+1,original_color,n,m,color);
        dfs(image,row,col-1,original_color,n,m,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int original_color=image[sr][sc];
        if(original_color!=color){
            dfs(image,sr,sc,original_color,n,m,color);
        }
        return image;
    }
};



//using bfs
class Solution {
public:
    void bfs(vector<vector<int>>&image,int row,int col,int color,vector<vector<int>>& visited){
        int n=image.size();
        int m=image[0].size();
        int original_color=image[row][col];
        image[row][col]=color;
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){
                    if(abs(deltarow+deltacol)==1){
                        int nrow=row+deltarow;
                        int ncol=col+deltacol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==original_color && !visited[nrow][ncol]){
                            image[nrow][ncol]=color;
                            visited[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color=image[sr][sc];
        if(original_color!=color){
            vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
            bfs(image,sr,sc,color,visited);
        }
        return image;
    }
};