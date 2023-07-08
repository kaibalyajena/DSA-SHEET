BinaryTreeNode<int>* findKthAncestorUtil(BinaryTreeNode<int> *root, int targetNodeVal, int &k,int &ans){
   if(root==nullptr){
       return nullptr;
   }
   if(root->data==targetNodeVal||findKthAncestorUtil(root->left,targetNodeVal,k,ans)!=nullptr||findKthAncestorUtil(root->right,targetNodeVal,k,ans)!=nullptr){
       if(k>0){
           k--;
       }else if(k==0){
           ans=root->data;
           return nullptr;
       }
       return root;
   }
   return nullptr;
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    int ans=-1;
    findKthAncestorUtil(root,targetNodeVal,k,ans);
    return ans;
}







bool kthAncestor(Node* root, int &k , int p) {
	if(root == NULL)
		return false;

	if(root->data == p) {
		return true;
	}
	bool leftAns = kthAncestor(root->left, k , p);
	bool rightAns = kthAncestor(root->right, k , p);
	//wapas aare honge
	//check left ya right me answer mila ya anhi
	if(leftAns || rightAns)
		k--;
	if(k == 0) {
		cout << "Answer: " << root->data << endl;
		k = -1;
    }
	return leftAns || rightAns;
}