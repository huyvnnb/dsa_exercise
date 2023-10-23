#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

node *buildTree(node *root){
	cout << "Enter the data: "<< endl;
	int data;
	cin >> data;
	root = new node(data);

	if(data == -1){
		return NULL;
	}

	cout << "Enter data for inserting left of: " << data << endl;
	root->left = buildTree(root->left);
	cout << "Enter data for inserting right of: " << data << endl;
	root->right = buildTree(root->right);
	return root;
}

node *buildTree_iterate(node *root){
	queue<node *> q;
	cout << "Enter root data: ";
	int data; cin >> data;
	root = new node(data);
	q.push(root);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		int leftData, rightData;
		cout << "Enter left data of " << temp->data << " : "; cin >> leftData;
		cout << "Enter right data of " << temp->data << " : "; cin >> rightData;
		if(leftData != -1){
			temp->left = new node(leftData);
			q.push(temp->left);
		}
		if(rightData != -1){
			temp->right = new node(rightData);
			q.push(temp->right);
		}
	}
	return root;
}

void printTree(node *root){
	//Level order traversal
	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		if(temp == NULL){
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout << temp->data << " ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

void printTree2(node *root){
	queue<node*> q;
	q.push(root);
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	printTree2(root->left);
	printTree2(root->right);
}

void printTree3(node *root){
	stack<node*> st;
	node*temp = root;
	st.push(temp);
	while(!st.empty()){
		node *temp = st.top();
		st.pop();
		if(temp->right->data != st.top()->data){
			st.push(temp->right);
			st.push(temp);
			st.push(temp->left);
		}
		if(temp->left == NULL || temp->right == NULL){
			cout << temp->data << " ";
		}
		if(temp->right->data == st.top()->data){
			cout << temp->data << " ";
		}
	}
}

int main(){
	node *root = NULL;
	// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	root = buildTree_iterate(root);
	cout << "Printing the tree" << endl;
	printTree(root);
	return 0;
}