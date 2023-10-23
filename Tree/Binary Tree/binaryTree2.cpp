#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int key){
		data = key;
		left = right = NULL;
	}
};

void inorder(node *root){
	if(!root){
		return;
	}
	cout << root->data << " ";
	inorder(root->left);
	inorder(root->right);
}

void delete_last(node *root, node *last){
	queue<node *> q;
	node *temp = root;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == last){
			root = NULL;
			delete (last);
			return;
		}
		if(temp -> left){
			if(temp->left == last){
				temp->left = NULL;
				delete(last);
				return;
			}
			else{
				q.push(temp->left);
			}
		}
		if(temp->right){
			if(temp->right == last){
				temp->right = NULL;
				delete(last);
				return;
			}
			else{
				q.push(temp->right);
			}
		}
	}
}

node *delete_node(node *root, int key){
	if(!root){
		return NULL;
	}
	if(root->left == NULL && root->right == NULL){
		if(root->data == key){
			return NULL;
		}
		else{
			return root;
		}
	}
	queue<node *> q;
	node *curr = root;
	//node *last_right_node = NULL;
	node *key_node = NULL;
	q.push(curr);
	while(!q.empty()){
		curr = q.front();
		q.pop();
		if(curr->data == key){
			key_node = curr;
		}
		if(curr->left){
			q.push(curr->left);
		}
		if(curr->right){
			q.push(curr->right);
		}
		// if(curr->left == NULL && curr->right == NULL){
		// 	last_right_node = curr;
		// }
	}
	if(key_node != NULL){
		key_node->data = curr->data;
		delete_last(root, curr);
	}
	return root;
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

	inorder(root);
	cout << endl;
	for(int i=1; i<=8; i++){
		root = delete_node(root, i);
		inorder(root);
		cout << endl;
	}
	//inorder(root);
	cout << endl;
	return 0;
}