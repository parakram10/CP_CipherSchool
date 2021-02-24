#include<bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

int findInInorder(vector<int> in, int k){
    for(int i=0;i<in.size();i++){
        if(in[i] == k) return i;
    }
    return -1;
} 

Tree* createTreeFromPreOrder(vector<int> pre, vector<int> in, int s, int e){
    static int i = 0;
    if(s>e) return NULL;
    Tree* root = new Tree(pre[i++]);
    if(s == e)  return root;
    int p = findInInorder(in,root->data);
    root->left = createTreeFromPreOrder(pre,in,s,p-1);
    root->right = createTreeFromPreOrder(pre,in,p+1,e);
    return root;
}

void printTree(Tree* root){
    if(!root)   return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> in = {1,2,4,5,3,6,7};
    sort(in.begin(),in.end());
    Tree* root = NULL;
    root = createTreeFromPreOrder(pre,in,0,in.size()-1);
    printTree(root);
}