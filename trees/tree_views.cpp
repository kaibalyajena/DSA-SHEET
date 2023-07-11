#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int x){
        this->data=x;
        left=nullptr;
        right=nullptr;
    }
};

node* buildTree(){
    cout<<"Enter the value of the node"<<endl;
    int val;
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    node* root=new node(val);
    cout<<"node left of node with value "<<val<<endl;
    root->left=buildTree();
    cout<<"node right of node with value "<<val<<endl;
    root->right=buildTree();
    return root;

}

void inorder(node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void topView(node* root){
    if(root==nullptr){
        return;
    }
    map<int,int> bottomNodesVal;
    queue<pair<node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* temp_node=temp.first;
        int hd=temp.second;
        if(bottomNodesVal.find(hd)==bottomNodesVal.end()){
            bottomNodesVal[hd]=temp_node->data;
        }
        if(temp_node->left){
            q.push(make_pair(temp_node->left,hd-1));
        }
        if(temp_node->right){
            q.push(make_pair(temp_node->right,hd+1));
        }
    }
    for(auto i:topNodesVal){
        cout<<i.second<<" ";
    }
    cout<<endl;
}



void bottomView(node* root){
    if(root==nullptr){
        return;
    }
    map<int,int> topNodesVal;
    queue<pair<node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* temp_node=temp.first;
        int hd=temp.second;
        topNodesVal[hd]=temp_node->data;
        if(temp_node->left){
            q.push(make_pair(temp_node->left,hd-1));
        }
        if(temp_node->right){
            q.push(make_pair(temp_node->right,hd+1));
        }
    }
    for(auto i:topNodesVal){
        cout<<i.second<<" ";
    }
    cout<<endl;
}


class Solution {
public:
    void preorder(TreeNode* root,int level,map<int,int> &mp){
        if(root!=nullptr){
            mp[level]=root->val;
            preorder(root->left,level+1,mp);
            preorder(root->right,level+1,mp);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        map<int,int> mp;
        preorder(root,0,mp);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};


class Solution {
public:
    void preorder(TreeNode* root,int level,map<int,int> &mp){
        if(root!=nullptr){
            if(mp.find(level)==m.end()){
                mp[level]=root->val;
            }
            preorder(root->left,level+1,mp);
            preorder(root->right,level+1,mp);
        }
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        map<int,int> mp;
        preorder(root,0,mp);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    node* root=buildTree();
    inorder(root);
    cout<<endl;
    topView(root);
    bottomView(root);
    return 0;
}