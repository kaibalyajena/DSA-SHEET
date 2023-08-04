class Solution {
public:
    void solve(int index,vector<int>& subset,vector<vector<int>>& ans,vector<int>& nums){
        ans.push_back(subset);
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            solve(i+1,subset,ans,nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0,subset,ans,nums);
        return ans;
    }
};