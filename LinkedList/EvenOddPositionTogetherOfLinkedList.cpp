// https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd

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

Node* evenOddPosition(Node* list){
    if(list==NULL) return NULL;
    Node* odd = list;
    Node* even = list->next;

    Node* temp = even;

    while(1){
        if(!odd || !even || !(even->next)){
            odd->next = temp;
            break;
        }

        odd->next = even->next;
        odd = even->next;

        if(odd->next == NULL){
            even->next = NULL;
            odd->next = temp;
            break;
        }

        even->next = odd->next;
        even = odd->next;
    }

    return list;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    Node* list  = NULL;
    for(int i=0;i<v.size();i++) insertInList(&list, v[i]);
    Node* res = evenOddPosition(list);
    printlist(res);
}