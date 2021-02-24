// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

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


Node* intersectedList(Node* head1, Node* head2){
    if(!head1 || !head2)    return NULL;
    int t1 = 0, t2 = 0;
    Node *h1 = head1, *h2 = head2;
    while(h1!=NULL){
        t1++;
        h1 = h1->next;
    }

    while(h2!=NULL){
        t2++;
        h2 = h2->next;
    }
    
    Node* temp = (h1>h2)?head1:head2;
    int k = abs(t2-t1);

    while(k>=0){
        temp = temp->next;
        k--;
    }

    return temp;
}


int main(){
     Node* newNode;
    Node* head1 = new Node(10);
    Node* head2 = new Node(3);
    newNode = new Node(6);
    head2->next = newNode;
    newNode = new Node(9);
    head2->next->next = newNode;
    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node(30);
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    cout<<"First List: ";
    printlist(head1);
    cout<<"\nSecond List: ";
    printlist(head2);
    Node* intersect = intersectedList(head1,head2);
    cout<<"\nIntersected List: ";
    printlist(intersect);
}