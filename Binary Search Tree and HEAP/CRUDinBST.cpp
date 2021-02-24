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

Tree* inOrderSucc(Tree* root){
    if(!root) return NULL;
    while(root->left){
        root = root->left;
    }
    return root;
}

Tree* deleteNode(Tree* root, int k){
    if(!root) return NULL;

    if(root->data < k){
        root->right = deleteNode(root->right, k);
    }else if(root->data > k){
        root->left = deleteNode(root->left, k);
    }
    else{
        if(root->left == NULL){
            Tree* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Tree* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Tree* p = inOrderSucc(root->right);
            root->data = p->data;
            root->right = deleteNode(root->right, p->data);
        }
    }
    return root;
}

int main(){
    vector<int> v = {5,20,3,9,93,49,12};
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = append(root,v[i]);
    inorder(root);
    cout<<"\n";
    int k = 20;
    root = deleteNode(root, k);
    inorder(root);
}