class Solution {
public:
    void solve(int start,int target,vector<vector<int>>& ans,vector<int>& comb,int k){
        if(target==0 && comb.size()==k){
            ans.push_back(comb);
            return;
        }else if(comb.size()>=k){
            return;
        }else if(target<0){
            return;
        }
        for(int i=start;i<=9;i++){
            comb.push_back(i);
            solve(i+1,target-i,ans,comb,k);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(1,n,ans,comb,k);
        return ans;
    }
};