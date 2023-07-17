class Solution {
public:
    bool dfs(vector<vector<char>>&grid, vector<vector<int>>&visited,int row,int col,int prevrow,int prevcol){
        //mark the curr row and curr col as visited
        visited[row][col]=1;
        //for horizontal and vertical traversal
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            // initialize and declare next row and next col for the next dfs call
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            //check if the next row and next col are inside the bounds of the grid and the element at that place in the grid is same as the element
            //present in the curr row and curr col of the grid and also check if next row and next col are not same as the prev row and prev col
            if(nrow<grid.size() && ncol<grid[0].size() && nrow>=0 && ncol>=0 &&grid[row][col]==grid[nrow][ncol] && (nrow!=prevrow || ncol!=prevcol)){
                //if same type of element not visited then do the dfs call for it
                if(!visited[nrow][ncol]){
                    //if any dfs calls return true and overall dfs becomes true so return true
                    if(dfs(grid,visited,nrow,ncol,row,col)){
                        return true;
                    }
                }else{
                    //if the element is already visited and is not the prev row and prev col then we have found a cycle so return true;
                    return true;
                }
            }
        }
        //if no cycle found in all dfs calls then return false
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        //traverse every element of the 2d grid and it is not visited then call dfs for it.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    //for every new dfs started the previous row and previous column is set to -1.
                    //if any dfs call return true (means cycle detected) we straightaway return true
                    if(dfs(grid,visited,i,j,-1,-1)){
                        return true;
                    }
                }
            }
        }
        //if after all dfs calls and all elements visited no cycle is detected then return false
        return false;
    }
};