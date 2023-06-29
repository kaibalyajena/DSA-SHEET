class Solution {
public:
    void combinationSumUtil(vector<int>& candidates,int target,vector<int>& comb,vector<vector<int>>& ans,int index){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        if(target<0){
            return;
        }
        //we have started the loop from index to avoid having duplicate solutions like [2,3,3] and [3,3,2]
        //try for possible combinations and backtrack
        for(int i=index;i<candidates.size();i++){
            comb.push_back(candidates[i]);
            target-=candidates[i];
            combinationSumUtil(candidates,target,comb,ans,i);
            //backtrack
            target+=candidates[i];
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSumUtil(candidates,target,comb,ans,0);
        return ans;
    }
};