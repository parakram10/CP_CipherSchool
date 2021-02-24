// https://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/

#include<bits/stdc++.h>
using namespace std;


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


void reverseAlternateNode(Node** node, int k){
    stack<Node*> s;
	Node* curr = *node;
	Node* prev = NULL;
	while(curr!=NULL){
		int count = 0;
		while(curr!=NULL && count<k){
			s.push(curr);
			curr = curr->next;
			count++;
		}

		while(s.size()>0){
			if(prev == NULL){
				prev = s.top();
				*node = prev;
				s.pop();
			}else{
				prev->next = s.top();
				prev = prev->next;
				s.pop();
			}

		}
        int l = k;
        while(l!=0){
            curr = curr->next;
            l--;
        }
	}
			prev->next = NULL;
}


int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* list = NULL;
    int k = 3;
    for(int i=0;i<v.size();i++) insertInList(&list,v[i]);
    printlist(list);
    reverseAlternateNode(&list,k);
    cout<<"\n";
    printlist(list);
}