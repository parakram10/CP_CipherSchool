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

Tree* makeTree(vector<int> v, int s, int e){
    if(s>e) return NULL;
    int mid = (s+e+1)/2;
    Tree* temp = new Tree(v[mid]);
    if(s == e) return temp;
    temp->left = makeTree(v,s,mid-1);
    temp->right = makeTree(v,mid+1,e);
    return temp;
}

void inorder(Tree* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int> v = {1,2,3,4};
    int n = v.size();
    Tree* ans = makeTree(v,0,n-1);
    inorder(ans);
}