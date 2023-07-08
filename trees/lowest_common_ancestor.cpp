class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* find,vector<TreeNode*>& path){
        if(root==nullptr){
            return false;
        }
        path.push_back(root);
        if(root->val==find->val){
            return true;
        }
        if(findPath(root->left,find,path)==true||findPath(root->right,find,path)==true){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        if(findPath(root,p,p_path)==false||findPath(root,q,q_path)==false){
            return nullptr;
        }
        int max_len=max(p_path.size(),q_path.size());
        int min_len=min(p_path.size(),q_path.size());
        for(int i=0;i<max_len-1;i++){
            if((p_path[i]==q_path[i])&&i==min_len-1){
                return p_path[i];
            }
            if(p_path[i+1]!=q_path[i+1]){
                return p_path[i];
            }
        }
        return nullptr;
    }
};




class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==p->val||root->val==q->val){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=nullptr&&right!=nullptr){
            return root;
        }else if(left!=nullptr){
            return left;
        }else{
            return right;
        }
    }
};