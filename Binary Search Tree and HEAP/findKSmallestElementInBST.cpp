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

int main(){
    vector<int> v = {20, 8, 22, 4, 12, 10, 14};
    int k = 3;
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = append(root, v[i]);
    vector<int> ans;
    inorder(root, ans);
    if(k>v.size()) cout<<"k is greater than number of elements in tree";
    else{
        cout<<ans[k-1];
    }
}