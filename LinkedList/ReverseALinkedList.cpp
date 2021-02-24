// https://www.geeksforgeeks.org/reverse-a-linked-list/

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

Node* reverseList(Node* root){
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
    return prev;
}


int main(){
	int a[] = {2,4,1,10,43,44,8,5};
    Node* node = NULL;
    for(int i=0;i<8;i++) insertInList(&node,a[i]);
    cout<<"Before Reversing the list ----->  ";
    printlist(node);
    cout<<"\nAfter Reversing the list ----->  ";
    node = reverseList(node);
    printlist(node);
}