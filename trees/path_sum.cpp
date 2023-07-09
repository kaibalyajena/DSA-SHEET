class Solution {
public:
    bool rootToLeaf(TreeNode* root,int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        if(root->right==NULL && root->left==NULL){
            sum+=root->val;
            if(targetSum==sum){
                return true;
            }
        }
        sum+=root->val;
        return (rootToLeaf(root->left,targetSum,sum)||rootToLeaf(root->right,targetSum,sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return rootToLeaf(root,targetSum,sum);
    }
};






//path sum 2
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int t,vector<int> v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        if(root->right==NULL && root->left==NULL && t==root->val){
            ans.push_back(v);
        }
        dfs(root->left,t-root->val,v);
        dfs(root->right,t-root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root,targetSum,v);
        return ans;
    }
};



//path sum 3
class Solution {
public:
    int count=0;
    void pathSumUtil(TreeNode* root,long long int target){
        if(root==nullptr){
            return;
        }
        if(target==root->val){
            count++;
        }
        pathSumUtil(root->left,target-root->val);
        pathSumUtil(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }
        pathSumUtil(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};