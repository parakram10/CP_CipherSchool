// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

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

Node* mergedList(Node* node1, Node* node2){
    if(node1 == NULL && node2 == NULL) return NULL;
    if(!node1) return node2;
    if(!node2) return node1;
    Node* node3 = NULL;
    while(node1!=NULL && node2!=NULL){
        if(node1->data > node2->data){
            insertInList(&node3, node2->data);
            node2 = node2->next;
        }
        else if(node1->data < node2->data){
            insertInList(&node3, node1->data);
            node1 = node1->next;
        }
    }
    while(node1!=NULL){
        insertInList(&node3, node1->data);
        node1 = node1->next;
    }

    while(node2!=NULL){
        insertInList(&node3, node2->data);
        node2 = node2->next;
    }

    return node3;
}


int main(){
    vector<int> a = {1,3,5,7,9,11};
    vector<int> b = {2,4,6,8,10};
    Node *node1 = NULL, *node2 = NULL, *node3 = NULL;
    for(int i=0;i<a.size();i++) insertInList(&node1,a[i]);
    for(int i=0;i<b.size();i++) insertInList(&node2,b[i]);
    node3 = mergedList(node1,node2);
    printlist(node3);
}