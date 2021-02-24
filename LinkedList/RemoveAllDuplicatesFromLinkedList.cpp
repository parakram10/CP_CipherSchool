// https://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/


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

void removeAllDuplicates(Node** node){

    Node* temp = new Node(-1);
    temp->next = *node;
    Node* curr = *node;
    Node* prev = temp;

    while(curr!=NULL){
        while(curr->next != NULL && prev->next->data == curr->next->data) curr = curr->next;

        if(prev->next == curr) prev = prev->next;

        else prev->next = curr->next;

        curr = curr->next;
    }
    
    *node = temp ->next;
}


int main(){
    vector<int> v = {1,2,2,2,3,4,4,4,4,5,6,6,6,6};
    int n = v.size();
    Node* node = NULL;
    for(int i=0;i<n;i++) insertInList(&node, v[i]);
    printlist(node);
    cout<<"\n";
    removeAllDuplicates(&node);
    printlist(node);
}