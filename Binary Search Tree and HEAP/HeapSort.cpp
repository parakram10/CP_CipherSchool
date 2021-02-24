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

void heapify(int harr[], int n, int index){
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    int smallest = index;
    if(l<n && harr[l] < harr[smallest]) smallest = l;

    if(r<n && harr[r] < harr[smallest])   smallest = r;

    if(smallest != index){
        swap(harr[smallest], harr[index]);
        heapify(harr,n,smallest);
    }
}

void heapSort(int harr[], int n){
    for(int i = n/2 - 1; i >= 0; i--) heapify(harr,n,i);
    for(int i = n-1; i>0; i--){
        swap(harr[0], harr[i]);
        heapify(harr, i, 0);
    }
}

void printArray(int harr[], int n){
    for(int i=0;i<n;i++) cout<<harr[i]<<"  ";
}

int main(){
    int harr[] = {12,11,13,5,6,7};
    heapSort(harr, 6);
    printArray(harr, 6);
}