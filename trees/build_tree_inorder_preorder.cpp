class Solution {
public:
    int preIndex=0;
    TreeNode* ctree(vector<int>& preorder, vector<int>& inorder,int si,int ei){
        if(si>ei){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex;
        for(int i=si;i<=ei;i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->left = ctree(preorder,inorder,si,inIndex-1);
        root->right = ctree(preorder,inorder,inIndex+1,ei);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* ans = ctree(preorder,inorder,0,n-1);
        return ans;
    }
};