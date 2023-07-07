#include<iostream>
#include<queue>
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

void postorder(node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void inorder(node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=nullptr){
            q.push(temp->left);
        }
        if(temp->right!=nullptr){
            q.push(temp->right);
        }
    }
}

void levelOrderLineByLine(node* root){
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }
}

int height(node* root){
    if(root==nullptr){
        return 0;
    }else{
        return 1+max(height(root->left),height(root->right));
    }
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(60);
    root->right->left->left = new node(50);
    root->right->right->right = new node(70);
    levelOrderLineByLine(root);
    cout<<height(root)<<endl;
    return 0;
}