// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x){
		data=x;
		next=NULL;
	}
};

void insertInList(Node** node,int x){
	if(*node==NULL){
		*node = new Node(x);
		return;
	}
	
	Node* curr = *node;
	Node* temp = new Node(x);
	while(curr->next!=NULL) curr = curr->next;
	curr->next = temp;
	return;
}


void printlist(Node* curr){
	while(curr!=NULL){
		cout<<(curr)->data<<" ";
		curr=(curr)->next;
	}
}

bool reverseList(Node* root){
    if(root == NULL) return root;

    Node* prev = NULL;
    Node* curr = root;
    Node* nxt;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    while(root!=NULL){
        if(root->data != prev->data) return false;
        root = root->next;
        prev = prev->next;
    }
    return true;
}


int main(){
	int a[] = {1,2,3,4,5,3,2,1};
    Node* node = NULL; 
    Node* newNode = NULL;
    for(int i=0;i<7;i++) insertInList(&node,a[i]);
    bool res = reverseList(node);
    if(res) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}