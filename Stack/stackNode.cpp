#include <bits/stdc++.h>
using namespace std;

struct stackNode{
	int data;
	stackNode *next;
};

stackNode *createNode(int x){
	stackNode *new_node = new stackNode;
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}

bool isEmpty(stackNode *root){
	return (!root);
}

void push(stackNode **root, int x){
	stackNode *new_node = createNode(x);
	new_node->next = *root;
	*root = new_node;
	cout << x << " is pushed into stack" << endl;
}

void pop(stackNode **root){
	if(isEmpty(*root)){
		cout << "Stack is empty" << " ";
	}
	stackNode *temp = *root;
	*root = (*root)->next;
	delete temp;
}

int peek(stackNode *root){
	if(isEmpty(root)){
		return INT_MIN;
	}
	return root->data;
}

int main(){
	stackNode *root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	cout << "Top element is " << peek(root) << endl;
	pop(&root);
	pop(&root);
	pop(&root);
	cout << "Top element is " << peek(root) << endl;
	return 0;
}