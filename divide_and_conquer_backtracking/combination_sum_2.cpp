class Solution {
public:
    void combinationSumUtil(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int> comb,int index){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            //do not include duplicate elements again 
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            //do not pick the element if it is greater than target
            //optimization
            if (candidates[i]>target) break;
            comb.push_back(candidates[i]);
            combinationSumUtil(candidates,target-candidates[i],ans,comb,i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sorting so that the duplicate elements are grouped are together
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSumUtil(candidates,target,ans,comb,0);
        return ans;
    }
};