// https://leetcode.com/problems/sort-list/


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

Node* findMiddle(Node* list){
    Node* ptr = list;
    Node* pptr = list;
    while(ptr!=NULL && pptr->next->next!=NULL){
        ptr = ptr->next;
        pptr = pptr->next->next;
    }

    Node* curr = ptr->next;
    ptr->next = NULL;
    return curr;
}

Node* mergeLists(Node* left, Node* right){
    Node* temp = new Node(10);
    Node* newNode = temp;
    while(left!=NULL && right!=NULL){
        if(left->data >= right->data){
            newNode->next = right;
            right = right->next; 
        }
        else{
            newNode->next = left;
            left = left->next;
        }
        newNode = newNode->next;
    }
    if(left!=NULL) newNode->next = left;
    if(right!=NULL) newNode->next = right;

    return temp->next;
}


Node* sortList(Node* list){
    if(list==NULL) return list;
    Node* mid = findMiddle(list);
    Node* left = sortList(list);
    Node* right = sortList(mid);
    return mergeLists(left,right);
}


int main(){
    vector<int> v = {1,45,2,6,10,7,22};
    Node* list = NULL;
    for(int i=0;i<v.size();i++) insertInList(&list, v[i]);
    printlist(list);
    cout<<"\n";
    Node* k = sortList(list);
    printlist(k);
}