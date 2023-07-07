class Solution {
public:
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }else{
            return 1+max(height(root->left),height(root->right));
        }
    }   
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }else{
            return max(height(root->left)+height(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        }
    }
};

class Solution {
public:
    int res=0;
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        res=max(res,lh+rh);
        return 1+max(lh,rh);
    }   
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};