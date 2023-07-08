class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int toSumTreeUtil(Node* node){
        if(node==nullptr){
            return 0;
        }
        int x=node->data;
        node->data=toSumTreeUtil(node->left)+toSumTreeUtil(node->right);
        return node->data+x;
    }
    void toSumTree(Node *node)
    {
        toSumTreeUtil(node);
    }
};