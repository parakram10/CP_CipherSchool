#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
        int data;
        Tree* left;
        Tree* right;
        Tree(int n){
            data = n;
            left = NULL;
            right = NULL;
        }
};

Tree* append(Tree* root, int d){
    if(root==NULL){
        root = new Tree(d);
        return root;
    }
    if(root->data < d){
        root->right = append(root->right, d);
    }
    else{
        root->left = append(root->left, d);
    }

    return root;
}


void inorder(Tree* root, vector<int>& ans){
    if(!root) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}


Tree* levelOrder(Tree* root, int data){
    if(root == NULL){
        return new Tree(data);
    }

    if(data <= root->data) root->left = levelOrder(root->left, data);
    else  root->right = levelOrder(root->right, data);

    return root;
}


Tree* createTree(vector<int> v, int n){
    if(n == 0) return NULL;

    Tree* root = NULL;
    for(int i=0;i<n;i++){
        root = levelOrder(root, v[i]);
    }
    return root;
}


void inorder(Tree* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    vector<int> v = {7,4,12,3,6,8,1,5,10};
    Tree* root = NULL;
    root = createTree(v,v.size());
    inorder(root);
}