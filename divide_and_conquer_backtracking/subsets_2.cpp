class Solution {
public:
    void solve(int index,vector<vector<int>>& ans,vector<int>& nums,vector<int>& subset){
        ans.push_back(subset);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            solve(i+1,ans,nums,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        solve(0,ans,nums,subset);
        return ans;
    }
};