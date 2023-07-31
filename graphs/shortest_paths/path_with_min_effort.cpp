//basically implemented dijkstra's algorithm with some modifications
//read question for understanding it
//{diff,{row,col}} this is priority queue
// when the reach the last element we return the difference (max diff between the cell value of the path from src to dest)
// tc E*log(V) or n*m*4*log(n*m)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delrow[]={0,0,1,-1};
        int delcol[]={-1,1,0,0};
        while(!pq.empty()){
            int difference=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return difference;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m){
                    int diff=max(difference,abs(heights[row][col]-heights[nrow][ncol]));
                    if(diff<dist[nrow][ncol]){
                        dist[nrow][ncol]=diff;
                        pq.push({diff,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};