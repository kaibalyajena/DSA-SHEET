#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  if( ((i>=0 && i < row) && (j >= 0 && j< col)) &&
      (arr[i][j] == 1 ) &&
      (visited[i][j]==false)) {
    return true;
  }
  else {
    return false;
  }
}

void solveMaze(int arr[][4], int row,int col, int i, int j,
vector<vector<bool> > &visited, vector<string>& path, string output  ) {

  //base case
  if(i == row-1 && j == col-1) {
    //answer found
    path.push_back(output);
    return;
  } 

  //Down -> i+1, j
  if(isSafe(i+1, j, row, col, arr, visited)) {
    visited[i+1][j] = true;
    solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtrack 
    visited[i+1][j] = false;
  }

  //Left -> i, j-1
  if(isSafe(i, j-1, row, col, arr, visited)) {
    visited[i][j-1] = true;
    solveMaze(arr, row, col, i, j-1, visited, path, output + 'L');
    //backtrack 
    visited[i][j-1] = false;
  }

  //Right -> i, j+1
  if(isSafe(i, j+1, row, col, arr, visited)) {
    visited[i][j+1] = true;
    solveMaze(arr, row, col, i, j+1, visited, path, output + 'R');
    //backtrack 
    visited[i][j+1] = false;
  }

  //Up-> i-1, j
if(isSafe(i-1, j, row, col, arr, visited)) {
    visited[i-1][j] = true;
    solveMaze(arr, row, col, i-1, j, visited, path, output + 'U');
    //backtrack 
    visited[i-1][j] = false;
  }


}

int main() {
  int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  for(auto i: path) {
    cout << i << " ";
  }
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

  
  return 0;
}




//compressed version
// class Solution{
//     public:
//     int movx[4]={1,-1,0,0};
//     int movy[4]={0,0,1,-1};
//     char out[4]={'D','U','R','L'};
//     bool isSafe(int i,int j,int row,int col,vector<vector<int>> &arr,vector<vector<bool>>&visited){
//         if((i<row&&i>=0)&&(j<col&&j>=0)&&arr[i][j]==1&&visited[i][j]==false){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     void solveMaze(vector<vector<int>> &arr,int row,int col,int i,int j,vector<string>& ans,string output,vector<vector<bool>>&visited){
//         if(i==row-1 && j==col-1){
//             ans.push_back(output);
//             return;
//         }
//         for(int ind=0;ind<4;ind++){
//             if(isSafe(i+movx[ind],j+movy[ind],row,col,arr,visited)){
//                 visited[i+movx[ind]][j+movy[ind]]=true;
//                 solveMaze(arr,row,col,i+movx[ind],j+movy[ind],ans,output+out[ind],visited);
//                 visited[i+movx[ind]][j+movy[ind]]=false;
//             }
//         }
//     }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         int row=n;
//         int col=n;
//         vector<string> ans;
//         if(m[0][0]==0){
//             ans.push_back("-1");
//             return ans;
//         }
//         string output="";
//         vector<vector<bool>> visited(row,vector<bool>(col,false));
//         visited[0][0]=true;
//         solveMaze(m,row,col,0,0,ans,output,visited);
//         return ans;
//     }
// };