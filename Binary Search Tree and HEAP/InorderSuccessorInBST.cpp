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

// Tree* findNode(Tree* root, Tree* k){
//     if(!root) return NULL;
//     if(root->data > k->data) return findNode(root->left,k);
//     else if(root->data < k->data) return findNode(root->right,k);
//     return root;
// }

// Tree* inorderSucc(Tree* root, Tree* k){
//     if(!root) return NULL;
//     Tree* l = findNode(root,k);
//     if(l==NULL) return NULL;

// }

void inorder(Tree* root, vector<int>& v){
    if(!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main(){
    vector<int> v = {20,8,22,4,12,10,14};
    vector<int> res;
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = append(root, v[i]);
    inorder(root, res);
    Tree* k = root->left->right->right;
    if(k == NULL) cout<<"NULL doesn't have inorderSuccessor";
    else{
        int i = 0;
        for(i=0;i<res.size();i++){
            if(res[i]==k->data){
                break;
            }
        }

        if(i == res.size()-1) cout<<"No inorder successor exists";
        else cout<<res[i+1]<<" is the inorder successor of "<<k->data;
    }
}