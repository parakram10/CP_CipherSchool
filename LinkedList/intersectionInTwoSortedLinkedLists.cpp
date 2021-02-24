// https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/


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


Node* intersectionList(Node* list1, Node* list2){
    Node* list = NULL;
    if(!list1 || !list2) return list;
    while(list1!=NULL && list2!=NULL){
        if(list1->data > list2->data) list2 = list2->next;
        else if(list2->data > list1->data) list1 = list1->next;
        else{
            insertInList(&list, list1->data);
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    return list;
}


int main(){
    vector<int> v1 = {1,2,3,4,5,6};
    vector<int> v2 = {1,2,5,6};
    Node *list1 = NULL, *list2 = NULL;
    for(int i=0;i<v1.size();i++) insertInList(&list1, v1[i]);
    for(int i=0;i<v2.size();i++) insertInList(&list2, v2[i]);

    Node* list = intersectionList(list1,list2);
    printlist(list);
}