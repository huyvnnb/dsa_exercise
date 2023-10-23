#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x) : data(x), next(NULL) {}
};

void pushFront(node **head, int x){
	node *new_node = new node(x);
	new_node->next = *head;
	if(*head != NULL){
		node *temp = *head;
		while(temp->next != *head){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	else{
		new_node->next = new_node;
	}
	*head = new_node;
}

void deleteKey(node **head, int key){
	if(*head==NULL){
		return;
	}
	node *temp = *head;
	node *prev = temp;
	if(temp->next == *head){
		*head = NULL;
		delete temp;
		return;
	}
	while(temp->data != key && temp->next != *head){
		prev = temp;
		temp = temp->next;
	}
	if(temp->data == key){
		if(temp == *head){
			node *last = temp;
			while(last->next != *head){
				last = last->next;
			}
			last->next = (*head)->next;
			*head = (*head)->next;
			delete temp;
		}
		else{
			prev->next = temp->next;
			delete temp;
		}
		
	}
}

void printList(node *head){
	node *temp = head;
	if(head != NULL){
		do{
			cout << temp->data << " ";
			temp = temp->next;
		}while(temp!=head);
	}
	cout << endl;
}
	
int main(){
	node *head = NULL;
	// for(int i=1; i<=1; i++){
	// 	pushFront(&head, i);
	// }
	pushFront(&head, 1);
	pushFront(&head, 2);
	pushFront(&head, 3);
	pushFront(&head, 1);
	printList(head);
	deleteKey(&head, 1);
	printList(head);
	return 0;
}