//just generate all the subsets and output only those who have k size
class Solution {
public:
    void solve(int num,int n,int k,vector<int> &comb,vector<vector<int>>& ans){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        for(int i=num;i<=n;i++){
            comb.push_back(i);
            solve(i+1,n,k,comb,ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(1,n,k,comb,ans);
        return ans;
    }
};