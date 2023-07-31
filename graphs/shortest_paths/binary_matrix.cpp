//gfg code only direction  //implemented djkistra and no need for a priority queue because the minimum distance nodes would be the front node the the distance is increasing uniformly so we can save on time complexity.
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        int delrow[]={1,-1,0,0};
        int delcol[]={0,0,1,-1};
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                    if(distance+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=distance+1;
                        q.push({distance+1,{nrow,ncol}});
                    }
                }
            }
        }
        if(dist[destination.first][destination.second]==INT_MAX){
            return -1;
        }
        return dist[destination.first][destination.second];
    }
};



//leetcode
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(delrow==0 && delcol==0){
                        continue;
                    }
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==0){
                        if(distance+1<dist[nrow][ncol]){
                            dist[nrow][ncol]=distance+1;
                            q.push({distance+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        if(dist[n-1][m-1]==INT_MAX){
            return -1;
        }
        return dist[n-1][m-1];
    }
};