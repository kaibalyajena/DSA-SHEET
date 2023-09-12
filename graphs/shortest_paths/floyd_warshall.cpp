//multi source shortest path
//also detects negative weight cycle
//go via every vertex from source to dest
//k are all the vertices
//min(d[src][k]+d[k][dest])
//if for any node the dist[k][k] becomes less than zero
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]==0;
	            }
	        }
	    }
        //main code is this part
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    //to detect negative weight cycle
	   // for(int i=0;i<n;i++){
	   //     if(matrix[i][i]<0){
	            
	   //     }
	   // }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};