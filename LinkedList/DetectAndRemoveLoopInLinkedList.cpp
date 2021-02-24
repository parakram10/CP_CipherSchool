// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/


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

bool isLoopPresent(Node* root){
	if(!root) return false;

	Node* ptr = root;
	Node* pptr = root;
	while(ptr && pptr && pptr->next){
		ptr = ptr->next;
		pptr = pptr->next->next;
		if(ptr == pptr) return true;
	}
	return false;
}

void removeLoop(Node** root){
	Node* ptr = *root;
	Node* pptr = *root;
	while(ptr && pptr && pptr->next){
		ptr = ptr->next;
		pptr = pptr->next->next;
		if(ptr == pptr) break;
	}
	ptr = *root;
	while(ptr->next != pptr->next){
		ptr = ptr->next;
		pptr = pptr->next;
	}

	pptr->next = NULL;
	cout<<"Loop is Removed";
}


int main(){
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    head->next->next->next->next->next = head->next->next;

    if(isLoopPresent(head)){
        cout<<"Loop is Present\n";
        removeLoop(&head);
		cout<<"\nList after removing loop : \n";
		printlist(head);
    }
	else{
		cout<<"Loop is not present";
	}
}