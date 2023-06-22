#include <iostream>
#include<vector>
using namespace std;

//to check if it is possible to go the destination through arr[i][j]
bool isSafe(int i, int j, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  //safe conditions
  // i and j must be inside the bounds of the arr
  // there must be path present on that point
  // it must not be visited earlier in the same path
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
  //we have reached the destination
  if(i == row-1 && j == col-1) {
    //answer found
    path.push_back(output);
    return;
  }
  //check if we can go left right down up and if so the go there.
  //Down -> i+1, j
  if(isSafe(i+1, j, row, col, arr, visited)) {
    visited[i+1][j] = true;
    solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtrack(make condition false so that the other recursive call has a fresh visited array)
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
  //the path
  //1 means we can go through that point
  int maze[4][4] = { {1,0,0,0}, {1,1,0, 1},{1,1,0,0},{0,1,1,1}};
  //if we can't enter the starting point then no path possible
  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }
  //size of the maze
  int row = 4;
  int col = 4;
  //make a visited boolean 2d matrix to remember the visited points of a single path 
  //so that we are not trapped inside an infinite loop like left right left right left right.
  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //mark the source as visited initially 
  visited[0][0] = true;
  //path vector will contain all the possible paths from source to destination
  vector<string> path;
  //output string would store a single possible path
  string output = "";
  //all possible paths would be pushed back to the path vector.
  solveMaze(maze,row,col, 0,0, visited, path, output);
  //print possible paths
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