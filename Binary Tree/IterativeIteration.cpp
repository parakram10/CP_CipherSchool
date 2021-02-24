#include <bits/stdc++.h>
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

Tree *insertIntoTree(Tree *root, int n)
{
    if (!root)
        return new Tree(n);
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree* curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        else
        {
            curr->left = new Tree(n);
            return root;
        }
        if (curr->right)
            q.push(curr->right);
        else
        {
            curr->right = new Tree(n);
            return root;
        }
    }
    return root;
}

void postorder(Tree *root)
{
    if(!root)   return;
    stack<Tree*> s,s1;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        s1.push(root);
        if(root->left) s.push(root->left);
        if(root->right) s.push(root->right);
    }

    while(!s1.empty()){
        cout<<s1.top()->data<<" ";
        s1.pop();
    }
}

void inorder(Tree *node)
{
    if (!node)
        return;
    Tree* root = node;
    stack<Tree*> s;
    while(1){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(s.empty()) return;

        root = s.top();
        s.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
    return;
}

void preorder(Tree *node)
{
    if (!node)
        return;
    Tree* root = node;
    stack<Tree*> s;
    while(!s.empty() || root!=NULL){
        while(root!=NULL){
            cout<<root->data<<" ";
            if(root->right) s.push(root->right);
            root = root->left;
        }
        if(!s.empty()){
            root = s.top();
            s.pop();
        }
    }
    return;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *root = NULL;
    for (int i = 0; i < v.size(); i++)
        root = insertIntoTree(root, v[i]);
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
}