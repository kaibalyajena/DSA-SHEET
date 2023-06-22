//using simple loops
class Solution {
public:
    void storeAns(vector<vector<char>>&board,int n,vector<vector<string>>&ans){
        vector<string> temp;
        for(int row=0;row<n;row++){
            string str="";
            for(int col=0;col<n;col++){
                str.push_back(board[row][col]);
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<char>>&board,int row,int col,int n){
        //check for another queen in the same row
        int i=row;
        int j=col;
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }
        //in the same bottom left diagonal
        i=row;
        j=col;
        while(i>=0 && j>=0){
             if(board[i][j]=='Q'){
                return false;
            }
            j--;
            i--;
        }
        //in the same top left diagonal
        i=row;
        j=col;
        while(i<n && j>=0){
             if(board[i][j]=='Q'){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    void nQueen(vector<vector<char>>&board,int col,int n,vector<vector<string>>&ans){
        if(col>=n){
            storeAns(board,n,ans);
            return;
        }
        //try to place queen in every row of a particular column if it is safe
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                nQueen(board,col+1,n,ans);
                //backtrack
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int col=0;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        nQueen(board,col,n,ans);
        return ans;
    }
};





//using unordered_map
class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> bottomLeftDiagonalCheck;
    unordered_map<int,bool> topLeftDiagonalCheck;
    void storeAns(vector<vector<char>>&board,int n,vector<vector<string>>&ans){
        vector<string> temp;
        for(int row=0;row<n;row++){
            string str="";
            for(int col=0;col<n;col++){
                str.push_back(board[row][col]);
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<char>>&board,int row,int col,int n){
        if(rowCheck[row]){
            return false;
        }
        if(bottomLeftDiagonalCheck[row+col]){
            return false;
        }
        if(topLeftDiagonalCheck[n-1+col-row]){
            return false;
        }
        return true;
    }
    void nQueen(vector<vector<char>>&board,int col,int n,vector<vector<string>>&ans){
        if(col>=n){
            storeAns(board,n,ans);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                rowCheck[row]=true;
                bottomLeftDiagonalCheck[row+col]=true;
                topLeftDiagonalCheck[n-1+col-row]=true;
                nQueen(board,col+1,n,ans);
                board[row][col]='.';
                rowCheck[row]=false;
                bottomLeftDiagonalCheck[row+col]=false;
                topLeftDiagonalCheck[n-1+col-row]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int col=0;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        nQueen(board,col,n,ans);
        return ans;
    }
};