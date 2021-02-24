// https://www.geeksforgeeks.org/length-longest-palindrome-list-linked-list-using-o1-extra-space/

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

int countSameNode(Node* a, Node* b){
	int count = 0;
	while(a!=NULL && b!=NULL){
		if(a->data == b->data){
			count++;
			a = a->next;
			b = b->next;
		}
		else break;
	}
	return count;
}

int latgestPalindromicSubList(Node* node){
	int count = 1;

	Node* prev = NULL;
	Node* curr = node;
	while(curr){
		Node* nxt = curr->next;
		curr->next = prev;

		count = max(count, 2*countSameNode(nxt,prev)+1);
		count = max(count, 2*countSameNode(nxt,curr));

		prev = curr;
		curr = nxt;
	}

	return count;
}


int main(){
    vector<int> a = {1,11,21,31,41,31,21,11,1};
    Node* v = NULL;
    for(int i=0;i<a.size();i++) insertInList(&v,a[i]);
    cout<<latgestPalindromicSubList(v);
}