#include <bits/stdc++.h>
using namespace std;

struct node{
	node *prev;
	int data;
	node *next;
	node(int x) : prev(nullptr), data(x), next(nullptr) {}
};

void pushFront(node **head, int x){
	node *temp = new node(x);
	temp->next = *head;
	if(*head != nullptr){
		(*head)->prev = temp;
	}
	*head = temp;
}

void insertAfter(node *prev_node, int x){
	node *new_node = new node(x);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	if(new_node->next != NULL){
		new_node->next->prev = new_node;
	}
}

void insertBefore(node **head, node *next_node, int x){
	node *new_node = new node(x);
	new_node->prev = next_node->prev;
	new_node->next = next_node;
	next_node->prev = new_node;
	if(new_node->prev != NULL){
		new_node->prev->next = new_node;
	}
	else{
		*head = new_node;
	}
}

void printFromHead(node *head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void printFromTail(node *head){
	node *temp = head;
	while(temp->next!=nullptr){
		temp = temp->next;
	}
	while(temp!=nullptr){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main(){
	node *head = nullptr;
	for(int i=1; i<=5; i++){
		pushFront(&head, i);
	}
	printFromHead(head);

	insertAfter(head, 100);
	insertBefore(&head, head->next, 1000);

	printFromTail(head);
	printFromHead(head);

	return 0;
}