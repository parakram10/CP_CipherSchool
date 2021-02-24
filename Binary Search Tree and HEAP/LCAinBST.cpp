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

void inorder(Tree* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Tree* LCAbst(Tree* root, int a, int b){
    if(!root) return NULL;

    if(root->data > a && root->data > b) return LCAbst(root->left,a,b);
    
    if(root->data < a && root->data < b) return LCAbst(root->right,a,b);

    return root;
}

int main(){
    vector<int> v = {5,10,3,11,6,8,4};
    Tree* root;
    for(int i=0;i<v.size();i++) root = append(root, v[i]);
    inorder(root);
    Tree* n = LCAbst(root,3,11);
    cout<<n->data;
}