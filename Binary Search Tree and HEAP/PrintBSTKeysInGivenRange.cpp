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


void printData(Tree* root, int k1, int k2){
    if(!root) return;
    if(k1 < root->data) printData(root->left , k1, k2);
    if(k1 <= root->data && k2 >= root->data) cout<<root->data<<" ";
    if(k2 > root->data) printData(root->right, k1, k2);
}


int main(){
    vector<int> v = {3,5,1,20,10,8,9,55};
    int k1 = 5, k2 = 20;
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = append(root, v[i]);
    inorder(root);
    cout<<"\n";
    printData(root, k1, k2);
}