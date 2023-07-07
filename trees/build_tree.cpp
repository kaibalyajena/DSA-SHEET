#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

node* buildTree(){
    int data;
    cout<<"Enter the value of the node"<<endl;
    cin>>data;
    if(data==-1){
        return nullptr;
    }
    node* root=new node(data);          
    cout<<"Enter the value for left of "<<data<<" node"<<endl;
    root->left=buildTree();
    cout<<"Enter the value for right of "<<data<<" node"<<endl;
    root->right=buildTree();
    return root;     
}

void preorder(node* root){
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node* root=nullptr;
    root=buildTree();
    preorder(root);
    return 0;
}