// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

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


Node* addLists(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return NULL;
    if(!root1) return root2;
    if(!root2) return root1;
    Node* res = NULL;
    int carry = 0;
    int sum = 0;
    while(root1!=NULL && root2!=NULL){
        int a = root1->data;
        int b = root2->data;
        int s = a+b;
        sum = s+carry;
        insertInList(&res, (sum%10));
        carry = sum/10;
        root1 = root1->next;
        root2 = root2->next;
    }
    while(root1!=NULL){
        int s = root1->data;
        sum = s+carry;
        insertInList(&res, (sum%10));
        carry = sum/10;
        root1 = root1->next;
    }

    while(root2!=NULL){
        int s = root2->data;
        sum = s+carry;
        insertInList(&res, (sum%10));
        carry = sum/10;
        root2 = root2->next;
    }

    if(carry!=0) insertInList(&res, carry);

    return res;
}


int main(){
    vector<int> a = {7,4,4,6};
    vector<int> b = {8,4};
    Node* root1 = NULL, *root2 = NULL;

    for(int i=0;i<a.size();i++)    insertInList(&root1,a[i]);
    for(int i=0;i<b.size();i++)    insertInList(&root2,b[i]);

    Node* sum = addLists(root1, root2);
    printlist(sum);
}