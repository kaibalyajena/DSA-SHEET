//modified djkistras
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000,INT_MAX);
        dist[start]=0;
        queue<pair<int,int>> q;
        //steps nums
        q.push({0,start});
        while(!q.empty()){
            int steps=q.front().first;
            int num=q.front().second;
            q.pop();
            if(num==end){
                return steps;
            }
            for(auto ele:arr){
                int new_num=(num*ele)%100000;
                if(steps+1<dist[new_num]){
                    dist[new_num]=steps+1;
                    q.push({steps+1,new_num});
                }
                if(new_num==end){
                    return steps+1;
                }
            }
        }
        return -1;
    }
};