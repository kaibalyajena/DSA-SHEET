class Solution {
public:
    TreeNode* cTree(vector<int>& inorder, vector<int>& postorder,int &postIndex,int inStart,int inEnd){
        if(postIndex<0||inStart>inEnd){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[postIndex]);
        postIndex--;
        int inIndex;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        //the recursive call for the right must be before the left
        // root right left
        root->right=cTree(inorder,postorder,postIndex,inIndex+1,inEnd);
        root->left=cTree(inorder,postorder,postIndex,inStart,inIndex-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIndex=n-1;
        return cTree(inorder,postorder,postIndex,0,n-1);
    }
};