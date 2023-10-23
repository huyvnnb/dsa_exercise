#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

void print_Inorder_Traversal(node *root){
	if(root== NULL){
		return;
	}
	print_Inorder_Traversal(root->left);
	cout << root->data << " ";
	print_Inorder_Traversal(root->right);
}

void print_Inorder_Traversal_iterate(node *root){
	stack<node *> st;
	node *curr = root;
	while(!st.empty() || curr != NULL){
		while(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}
}

void print_Preorder_Traversal(node *root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	print_Preorder_Traversal(root->left);
	print_Preorder_Traversal(root->right);
}

void print_Preorder_Traversal_iterate(node *root){
	stack<node *> st;
	node *curr = root;
	st.push(curr);
	while(!st.empty()){
		curr = st.top();
		st.pop();
		cout << curr->data << " ";
		if(curr->right != NULL){
			st.push(curr->right);
		}
		if(curr->left != NULL){
			st.push(curr->left);
		}
	}
}

void print_Postorder_Traversal(node *root){
	if(root == NULL){
		return;
	}
	print_Postorder_Traversal(root->left);
	print_Postorder_Traversal(root->right);
	cout << root->data << " ";
}

void print_Postorder_Traversal_iterate(node *root){
	stack<node *> st;
	node *curr = root;
	while(!st.empty() || curr != NULL){
		while(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		if(curr->right == NULL){
			st.pop();
			cout << curr->data << " ";
			while(!st.empty() && st.top()->right == curr){
				curr = st.top();
				st.pop();
				cout << curr->data << " ";
			}
		}
		if(!st.empty()){
			curr = st.top()->right;
		}
		else{
			curr = NULL;
		}
	}
}

void insertNode(node **root, int key){
	node *new_node = new node(key);
	if(*root == NULL){
		*root = new_node;
		return;
	}

	queue<node *> q;
	node *curr = *root;
	q.push(curr);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		if(temp->left != NULL){
			q.push(temp->left);
		}
		else{
			temp->left = new_node;
			return;
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}
		else{
			temp->right = new_node;
			return;
		}
	}
}

int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);;
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->right = new node(7);
	root->left->right->left = new node(8);
	print_Inorder_Traversal(root);
	cout << endl;
	insertNode(&root, 1000);
	print_Inorder_Traversal(root);
	return 0;
}



