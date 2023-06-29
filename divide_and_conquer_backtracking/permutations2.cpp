class Solution {
public:
    void permuteUniqueUtil(vector<int>& nums,vector<vector<int>>& ans,int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        //to remove duplicate permutations
        unordered_map<int,bool> visited;
        for(int i=index;i<nums.size();i++){
            if(visited.find(nums[i])!=visited.end()){
                continue;
            }
            visited[nums[i]]=true;
            swap(nums[i],nums[index]);
            permuteUniqueUtil(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueUtil(nums,ans,0);
        // set<vector<int>> st;
        // for(auto i:ans){
        //     st.insert(i);
        // }
        // ans.clear();
        // for(auto i:st){
        //     ans.push_back(i);
        // }
        return ans;
    }
};